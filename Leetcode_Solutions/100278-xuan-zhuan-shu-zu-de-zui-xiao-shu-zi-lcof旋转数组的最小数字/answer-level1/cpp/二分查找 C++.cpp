将数组分作[a,b]两部分，a为原数组未旋转部分，b为旋转部分
例如[3,4,5,1,3], a=[3,4,5], b=[1,3], 因为原数组为非递减序列，则min(a)>=max(b)
因此，在二分查找的过程中，
1. 若num[mi]>numb[hi]，此时指针mi仍在a中，将lo跳转至mi+1处；
2. 若num[mi]<numb[hi]，此时指针mi在b中，将hi跳转至mi处；
3. 若num[mi]==num[lo]，无法确定是否跳过最小数字，将hi减1逐步试探。
```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int lo = 0, hi = numbers.size()-1;
        while(lo<hi){
            int mi = (lo+hi)/2;
            if(numbers[mi]<numbers[hi])
                hi = mi;
            else if (numbers[mi]>numbers[hi])
                lo=mi+1;
            else hi--;
        }
        return numbers[lo];
    }
};
```
