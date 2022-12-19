### 解题思路
此处撰写解题思路

### 代码

```c
bool isPerfectSquare(int num){

    if (num <= 0) {
        return false;
    }

    if (num == 1) {
        return true;
    }

    //分段缩小搜索范围
    long long root = num/2;
    while (((root*root) > num) && ((root*root/4) >= num)) {
        root = root/2;
    }

    //上一步的分段让root已经逼近平方数，这里从大到小搜索会更快
    for (long long i = root; i >= 2; i--) {
        if (i*i == num) {
            return true;
        }
        else if (i*i < num) { //平方如果已经小于num就没必要浪费时间再遍历更小的i了
            return false;
        }
    }

    return false;
}
```