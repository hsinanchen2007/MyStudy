
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        
       
        int j=0;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                j++;
            }
            else{
                k++;
            }
        }
        vector<int>  ji(k);
        vector<int>  ou(j);
        int q=0;
        int p=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ou[q++]=nums[i];
            }
            else{
                ji[p++]=nums[i];
            }
        }
   
        ou.insert(ou.begin(),ji.begin(),ji.end());
        return ou;

    }
};