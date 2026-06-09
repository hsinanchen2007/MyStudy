//自己写个哈希表就行了
class Solution {
public:
struct Node{
    int val;
    Node* next;
};
const int hashLength=100000;
    bool containsDuplicate(vector<int>& nums) {
        Node* hashMap[hashLength];
        for(int i=0;i<hashLength;i++){
            hashMap[i]=nullptr;
        }
        for(int i=0;i<nums.size();i++){
            Node* now=hashMap[abs(nums[i])%hashLength];
            if(now==nullptr){
                hashMap[abs(nums[i])%hashLength]=new Node;
                hashMap[abs(nums[i])%hashLength]->val=nums[i];
                hashMap[abs(nums[i])%hashLength]->next=nullptr;
            }else{
                while(now->next!=nullptr){
                    if(now->val==nums[i]) return true;
                    now=now->next;
                }
                if(now->val==nums[i]) return true;
                now->next=new Node;
                now=now->next;
                now->next=nullptr;
                now->val=nums[i];
            }
        }
        return false;
    }
};