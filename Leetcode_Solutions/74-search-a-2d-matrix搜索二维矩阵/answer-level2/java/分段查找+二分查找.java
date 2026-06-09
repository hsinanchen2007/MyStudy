## 1、分段查找

本质上还是暴力破解，但是借助归并的思想将数组分段，可以降低遍历数量级。

将矩阵的每行首位和末位，与target比较后如果区间覆盖，就进入行数组遍历。

时间复杂度最好的情况是O(m)，最差的情况是O(m+n).

代码：

执行用时 : 0 ms, 在所有 Java 提交中击败了100.00%的用户

内存消耗 :  42.1 MB, 在所有 Java 提交中击败了21.18%的用户

```java
public boolean searchMatrix(int[][] matrix, int target){
    if (matrix.length ==0) return false;
    
    // 按行遍历矩阵m次
    for (int[] sub:matrix){
        if (sub.length ==0) return false;
        // 将矩阵的每行首位和末位，与target比较进入行数组
        if (sub[0]<=target && target <= sub [sub.length -1]){
            // 行数组内遍历元素n次
            for (int ele:sub){
                if (ele == target)
                    return true;
            }
            // 覆盖区间外的行数组不必再判断
            break;
        }
    }
    return false;
}
```



## 2、二分查找

查看题目：行数组内递增，每行之间递增，所以整个矩阵就是个递增序列。

使用二分查找，关键在于序列下标index在规则的mxn矩阵中，index/n可以定位行，index%n可以定位列。

其余的与普通二分查找没区别。序列的总长度是mxn，所以时间复杂度是O(log(mn)).

与分段查找相比，二分查找在数据量大的情况下优势依然明显。

代码：

执行用时 : 0 ms, 在所有 Java 提交中击败了100.00%的用户

内存消耗 : 42 MB, 在所有 Java 提交中击败了23.77%的用户

```java
public boolean searchMatrix(int[][] matrix,int target){
    int m = matrix.length;
    if (m==0) return false;
    int n = matrix [0].length;

    int left =0; int right = m*n-1;
    int halfIndex, halfEle;
    while (left <= right){
        halfIndex = (left + right)/2;
        halfEle = matrix [halfIndex/n][halfIndex%n];
        if (halfEle==target) return true;
        else{
            if (target<halfEle) right=halfIndex-1;
            else left=halfIndex+1;
        }
    }
    return false;
}
```

