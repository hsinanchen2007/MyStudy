执行用时 :16 ms, 在所有 C++ 提交中击败了92.24% 的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1=-1,index2=-1;
        int num1,num2;
        int size=nums1.size()+nums2.size();
        bool b=size%2==0?false:true;//true奇数个元素,false偶数个元素
        if(b){
            index1=size/2;
        }else{
            index1=size/2-1;
            index2=index1+1;
        }
        int i=0,j=0;
        while(i+j!=index1){
            compare(i,j,nums1,nums2);
        }
        num1=compare(i,j,nums1,nums2);

        if(b){
            return num1;
        }else{
             num2=compare(i,j,nums1,nums2);
            return (num1+num2)/2.0;
        }
    }
private:
    int compare(int& i,int & j,vector<int>& nums1, vector<int>& nums2){
        int num;
        int max_1 = nums1.size() - 1;
        int max_2 = nums2.size() - 1;
        if (i>max_1) {
            num= nums2.at(j++);
            return num;
        }
        else if (j > max_2) {
            num= nums1.at(i++);
            return num;
        }
        else {
            if (nums1.at(i) < nums2.at(j)) {
                num = nums1.at(i);
                i++;
            }
            else {
                num = nums2.at(j);
                j++;
            }
        }
        return num;
    }
};
```