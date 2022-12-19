![CA3A2E2608DD26654944F60F6528B5CE.jpg](https://pic.leetcode-cn.com/0347f3bca23aeb3714f50a89eecccee712f67780581df898042b2533e2893c4d-CA3A2E2608DD26654944F60F6528B5CE.jpg)

# Method1:
将B中的元素依次添加到A的尾部，然后再排序。
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i=0;i<n;i++)
            A[m+i]=B[i];
        sort(A.begin(),A.end());
    }
};
```
# Method2:
用两个指针分别指向A、B的末尾元素，依次比较，较大的元素放置A的末尾。
当A已经就比较完，而B中还有元素时，直接将B中的元素放置A的头部。
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pt_A=m-1;//指向A的末尾元素
        int pt_B=n-1;//指向B的末尾
        int cur=m+n-1;//指向A的末尾
        
        while(pt_A>=0 && pt_B>=0)
        {
            if(A[pt_A]>B[pt_B])//A的末尾元素>B的末尾元素
            {
                A[cur]=A[pt_A];//将A的末尾元素放置A的末尾
                cur--;
                pt_A--;
            }
            else
            {
                A[cur]=B[pt_B];//反之，将B的末尾元素放置A的末尾
                cur--;
                pt_B--;
            }
        }
        while(pt_B>=0)//A的元素已经比较完毕，而B中还有元素
        {
            A[pt_B]=B[pt_B];//直接将B中的元素放到A中
            pt_B--;
        }
    }
};
```

