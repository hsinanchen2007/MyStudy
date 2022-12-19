### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for (int i = 0; i < n; i ++){
            int j = m - 1;//nums1的末尾
            int tmp = nums2[i];//从nums2中取出一个元素，插入到nums1中
            while (j >= 0 && (nums1[j] >  tmp) ){
                //大的往后移动，寻找合适的位置
                nums1[j+1] = nums1[j];
                j --;
            }
            nums1[j+1] = tmp;
            m++;//插入完成后，nums1的长度加1
        }
    }
};
```