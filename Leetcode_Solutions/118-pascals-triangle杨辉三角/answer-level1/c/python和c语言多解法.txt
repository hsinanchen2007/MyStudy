### 解题思路
此处撰写解题思路

### 代码
c 代码解法
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;//returnSize是真相一个整数的指针，表示返回杨辉三角的行数 = 输入numRows
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));//returnColumnSizes是指向一个数组的指针，数组元素为对应行的元素个数
    int **res = (int**)malloc((*returnSize) * sizeof(int*));//res是一个指针，它指向的是由指针构成的数组，每个指针都指向对应的三角的一行数；res也是二维数组
    int i = 0;
    for(; i < *returnSize; i++){
        (*returnColumnSizes)[i] = i + 1;
        res[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
        res[i][0] = 1;
        res[i][i] = 1; 
    }
    for(i = 2; i <= numRows - 1; i++){
        for(int j = 1; j < i; j++){
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}
```
python解法1
```
class Solution:
    def generate(self, numRows) :
        """
        input: numRows: int
        return : List[List[int]]
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

        """
        #List 用法与c语言数组不同，无法在确认数组大小后直接给二元数组赋值
        #List 必须一个一个的append，首先在二维数组中，每增加一行，得增加一个[]。每增加一列得append赋值一次
        #方法一两个for循环嵌套法 ，先赋初值[0,0],[1,0],[1,1]。然后给j等于0和i的时候赋初值。最后递推关系求解
        sTriangle = []
        for i in range(numRows):
            sTriangle.append([])
            for j in range(0,i+1):
                print(i,j)
                if i == 0 or i == 1 :
                    sTriangle[i].append(1)  
                elif j == 0 or j == i :
                    sTriangle[i].append(1)
                else :
                    temp= sTriangle[i-1][j-1] + sTriangle[i-1][j]
                    sTriangle[i].append(temp)
        return sTriangle

```
python 解法2
```
def generate2(self, numRows) :
        """
        input: numRows: int
        return : List[List[int]]
        """
        """
        方法2，使用函数递归法，与方法1相比，函数递归代替了一层for嵌套。因为函数得从第一行[0,0]开始，所以使用if条件句来作为跳出递归的条件
        语句精讲：值得注意的是，python中的i + = 1 与 c语言中的i++自增不同。
        c语言中的自增是在不改变i变量地址的情况改变地址指向内容。python是通过i=i+1改变了变量，改变了变量地址。
        +=是改变变量，相当于重新生成一个变量，把操作后的结果赋予这个新生成的变量。
        --是改变了对象本身，而不是变量本身，即改变数据地址所指向的内存中的内容。
        python中的数字类型是不可变数据，也就是数字类型数据在内存中不会发生改变。当变量值发生改变时，
        会新申请一块内存赋值为新值，然后将变量指向新的内存地址
            
        """
        sTriangle=[]
        row0 =0
        def genTri(i):
            """
            i:row
            j: column
            """
            if i >= numRows:
                return
            sTriangle.append([])
            for j in range(0,i+1):

                if i == 0 or i == 1 :
                    sTriangle[i].append(1)  
                elif j == 0 or j == i :
                    sTriangle[i].append(1)
                else :
                    temp= sTriangle[i-1][j-1] + sTriangle[i-1][j]
                    sTriangle[i].append(temp)
            i += 1
            genTri(i)
        genTri(row0)
        return sTriangle
```
