**思路：**
题目要求既要比原数组小，又要在所有比原数组小的当中选最大，改动越靠后的数字影响越小，所以考虑逆序。
对于第i个元素，查找靠右的剩下元素中既比i元素小，又尽量最大的元素，如果存在这样的元素，交换即可得到结果。
**举例：**
对于数列[1,9,4,6,7]，逆序查找，最后一个元素因为后面没有元素，不用查，从倒数第二个元素查起。对于元素6，靠右的元素只有7，且比6大，不满足条件，同样对于元素4，也不满足条件，对于元素9，靠右的元素分别为4，6，7，这三个元素中最大的是7，且比9小，满足条件，因此交换7和9即可得到最后的答案。
![1578466959.jpg](https://pic.leetcode-cn.com/d7f1a9080a25939ca188fd40582c612ef5f7f9beab72fc4ce79931375c8bdcd9-1578466959.jpg)


```
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int len = A.length;
        for(int i=len-2;i>=0;i--){
            int max = i+1;
            for(int j=i+1;j<len;j++){
                if(A[j]>A[max] && A[j]<A[i]){
                    max = j;
                }
            }

            if(A[i]>A[max]){
                int temp = A[i];
                A[i] = A[max];
                A[max] = temp;
                return A;
            }
        }
        return A;
    }
}
```
