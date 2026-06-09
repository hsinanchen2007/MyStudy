### 解题思路
此处撰写解题思路

### 代码

```cpp
//求中位数的暴力方法
/*
1、使用multiset的排序功能
2、在向multiset中insert数据的时候同时移动指向中位数的指针。
3、本题的关键就在于在向multiset中插入数据时如何移动指向中位数的指针。----》请参考addNum()函数的实现。
*/
class Solution {
public:
    multiset<int> m_set;
    multiset<int>::iterator mid_iterator;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        buildMultiset(nums1,nums2);
        return findMedian();       
    }

    void buildMultiset(vector<int>& nums1, vector<int>& nums2){

        for(int i = 0;i < nums1.size();i++){
            addNum(nums1[i]);
        }

        for(int i = 0;i < nums2.size();i++){
            addNum(nums2[i]);
        }
    }

    void addNum(int num){
        m_set.insert(num);
        int size = m_set.size();
        if(size == 1){
            mid_iterator = m_set.begin();
        }else if(((size % 2) == 1) && (*mid_iterator <= num)){
            mid_iterator++;
        }else if(((size % 2) == 0) && (*mid_iterator > num)){
            mid_iterator--;
        }
    }

    double findMedian(){
        int size = m_set.size();
        if(size % 2 == 1){//k是奇数
            return *mid_iterator;
        }

        return 0.5 * ((double)*mid_iterator + (double)*next(mid_iterator));//k是偶数
    }

    
};
```