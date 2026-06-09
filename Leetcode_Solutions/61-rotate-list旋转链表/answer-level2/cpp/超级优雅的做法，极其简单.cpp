### 解题思路
假设12345，移动k位，其实我们可以将前size-k位翻转为32145，然后再翻转后面k位为32154，然后全部翻转为
45123，看看正确答案是不是出来了。详细看代码

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *build(vector<int>& nums ){
        ListNode *root=new ListNode(nums[0]);
        ListNode *head=root;
        for(int index=1;index<nums.size();index++){
            root->next=new ListNode(nums[index]);
            root=root->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *root=head;
        vector<int> nums;
        if(root==NULL)return root;
        while(root!=NULL){
            nums.push_back(root->val);
            root=root->next;
        }
        int size=nums.size();
        k%=size;
        if(k==0)return head;
        else{
            reverse(nums.begin(),nums.begin()+size-k);//前size-k个反转
            reverse(nums.begin()+size-k,nums.end());//后面k个进行反转
            reverse(nums.begin(),nums.end());
            root=build(nums);
        }
        return root;

        
    }
};
```