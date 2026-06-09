##解题思路
第一反应是用堆，维持一个大小为K的堆。
1. 首先自己建堆，构建堆的核心就是三个公式
   父结点索引：(i-1)/2，
   左孩子索引：2*i+1
   右孩子索引：2*i+2
2. 方法：每次新插入的数据都与其父结点进行比较，如果插入的数比父结点大，则与父结点交换，否则一直向上交换，直到小于等于父结点，或者来到了顶端（寻找父节点采用索引，父结点索引：(i-1)/2）
```C++ []
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) return vec; // 排除 0 的情况
        for (int i = 0; i < k; i++) vec[i] = arr[i];
        heapInsert(vec);
        for (int i = k; i < arr.size(); i++)
            if (vec[0] > arr[i]){
                vec[0] = arr[i];
                heapInsert(vec);
                // heapify(vec,0,k-1);
            }
        return vec;
    }
    void heapInsert(vector <int>& arr){
        int size = arr.size();
        // for ()
        for (int i = 0;i < size; i++){
            int currentindex = i;
            int fatherindex = (currentindex  - 1)/2;
            while (arr[currentindex] > arr[fatherindex]){
                swap(arr[currentindex], arr[fatherindex]);
                currentindex = fatherindex;
                fatherindex = (currentindex - 1)/2;
            }
        }
    }
};
```