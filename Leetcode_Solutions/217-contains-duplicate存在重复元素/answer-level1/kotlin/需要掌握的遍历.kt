### 解题思路
遍历中“暴力解法”的常规武器，个人认为，一般只有把暴力解法想出来，然后去作出相应优化或者是理解高级解法时会得心应手...

遍历如“数组”亦或是“字符串”，且需要知道其中的元素关系
暴力写法的两种循环

     for (i in 0 until nums.size) {
        for (j in 0 until i) {
           // TODO  
        }
    }
 for (i in 0 until nums.size) {
        for (j in i+1 until nums.size) {
         // TODO 
        }
    }