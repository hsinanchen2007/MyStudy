**解法1：双指针法**
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
      int i=0,j=s.size()-1;//双指针，两端同时向中间移动
      while(i<j){swap(s[i],s[j]);++i;--j;}
    }
};
```
**解法2：递归法**
```cpp
class Solution {
public:
    void reverseString(vector<char>& s){
        reverseString(s,0,s.size()-1);
    }
    void reverseString(vector<char>& s,int i,int j){
        //1:递归边界
        if(i>=j)return;
        //2:递归式
        swap(s[i],s[j]);
        reverseString(s,i+1,j-1);
    }
};
```
**解法3：STL算法**
```cpp
class Solution {
public:
    void reverseString(vector<char>& s){
        reverse(s.begin(),s.end());
    }
};
```
