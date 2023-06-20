/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head){
        if (head == nullptr || head->next == nullptr)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        if (fast != nullptr) {
            slow = slow->next;
        }
        
        while (prev != nullptr && slow != nullptr) {
            if (prev->val != slow->val)
                return false;
            
            prev = prev->next;
            slow = slow->next;
        }
        
        return true;
    }
};

// bool Solution::isPalindrome(ListNode *head){
//     ListNode *first;
//     ListNode *last;
//     ListNode *temp;
//     ListNode *half;

//     int i = 0;
//     int x = 0;
//     int n = 0;
//     int l = 0;
//     temp = head;
//     while (temp->next != NULL){
//         temp = temp->next;
//         i++;
//     }
//     x = i;
//     i = i + 1;
//     n = i - 2;
//     i = i / 2;
//     last = temp;
//     first = head;
//     if (x == 1 || x == 2) {
//         if (first->val != last->val)
//             return false;
//         else
//             return true;     
//     }
//     if (x == 0) return true;
//     l = i;
//     temp = head;
//     while (l--){
//         temp = temp->next;
//     }
//     half = temp;
//     temp = head;
//     l = 0;
//     while (i){
//         if (first->val != last->val)
//             return false;
//         first = first->next;
//         //last = NULL;
//         if (n % 2 == 0)
//             l = n / 2;
//         else
//             l = n / 2 + 1;
//         while (l > -1){
//             temp = temp->next;
//             l--;
//         }
//         last = temp;
//         temp = half;
//         i--;
//         n--;
//     }
//     return true;
// }