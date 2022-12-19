大一新生一枚，初来乍到，请多关照。
完全参照作者Q_嗯的解法，进行了进一步的修改，如有不对的地方还请批评指针（侵删）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> Nums;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j])==target){
                    Nums.push_back(i);
                    Nums.push_back(j);
                }
            }
        }
         Nums.resize(Nums.size()/2+1);   //主要就是修改了这里，因为在上边的if循环中，                                             i，j会重复出现一次只不过位置颠倒了而已，                                              所以这里使用了resize()函数对原数组进行删减
         return Nums;
}
};