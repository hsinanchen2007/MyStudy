解题思路：构造长度为128，值为0的数组，遍历字符串并在每一步中将数组中对应ascall码下标的元素加一；最后遍历数组检查有无大于一的值即可判断。
```
class Solution {
public:
    bool isUnique(string astr) {
       vector<int>arr(128,0);
       for(int i=0;i<astr.size();i++){
           arr[astr[i]]++;
       }
       for(int i=0;i<128;i++){
           if(arr[i]>1){
               return false;
           }
       }
       return true;}
};
```


