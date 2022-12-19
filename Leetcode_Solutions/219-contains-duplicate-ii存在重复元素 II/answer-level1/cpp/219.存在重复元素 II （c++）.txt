//除去暴力搜索，依旧是两个思路
//思路一：先对数组进行sort排序（o（nlogn）），再遍历排序后数组，比较相邻的两个数是否相同。与问题Ⅰ不同的是，这里需要构造一个结构体来记录元素对应的位置，并重写comp（）函数以便对结构体数组使用sort（）排序。
/*struct ElementWithPosition
{
    int num;
    int pos;
};

class Solution {
public:
    bool static comp(ElementWithPosition a,ElementWithPosition b){
        return a.num<b.num;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()||k<=0)
            return false;
        ElementWithPosition eles[nums.size()];
        for(int i=0;i<nums.size();i++){
            eles[i].num=nums[i];
            eles[i].pos=i;
        }
        sort(eles,eles+nums.size(),comp);
        for(int i=1;i<nums.size();i++){
            if ( eles[i].num == eles[i-1].num && abs(eles[i].pos - eles[i-1].pos) <= k )
            return true;
        }
        return false;
    }
};*/

//思路二：利用哈希散列（n）。利用 hashmap, key 为 vector 中的数, value 存放对应的下标。 遍历 vector, 若当前值已经存在于 hashmap 中，判断当前的下标与 hashmap 中记录的下标差是否不大于 k, 若是，返回 true; 否则，更新 hashmap 中该值的下标，继续下一个数。
class Solution {
public:    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i =0; i < nums.size(); i++)
        {
            if(map.count(nums[i])!=NULL&&i-map[nums[i]]<=k) return true;
            map[nums[i]] = i;
        }
            return false;
        }
};