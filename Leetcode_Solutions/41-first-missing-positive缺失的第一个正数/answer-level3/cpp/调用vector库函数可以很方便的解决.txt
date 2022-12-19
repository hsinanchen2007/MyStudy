```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    vector<int>::iterator result ;//定义一个迭代器
        /*
        中心思想就是从最小正整数1开始依次递增查找，当result等nums.end()的时候
        就代表这个数组中没有这个整数  那么这个整数就是缺失的最小正整数！！！
        代码比较简洁 想法也比较简单
*/
        for(int i=1 ; ;i++){
            result=find( nums.begin( ), nums.end( ),i );
            if(result==nums.end()){
                    return i;
            }
        }
        return 0;
    }
};
```
