从题解：
![image.png](https://pic.leetcode-cn.com/4f27c4a696908d33f10bbfbb9e3ecc2ec76bf0f6890c07684a2a031c365d13b2-image.png)
中受到启发

先分，然后找到左边的优胜者，在找到右边的优胜者，然后看哪个数字个数多，个数多的数字作为本轮的优胜者，并返回。
具体实现参考代码如下：

```
/*
 * 参数说明：
 * l：左边界
 * r：右边界
 * win：[l,r)的优胜者
 * n：[l,r)的优胜者，进过battle之后，剩下的数字个数
 */
void div_con(vector<int>& nums, int l, int r, int& win, int& n){
    if(l+1>=r) {
        win = nums[l];
        n = 1;
        return ;
    }
    int m = (r-l)/2 + l;
    int lwin, ln;
    div_con(nums, l, m, lwin, ln); // 找到左边的优胜者
    int rwin, rn;
    div_con(nums, m, r, rwin, rn); // 找到右边的优胜者

    if(lwin == rwin){ // 如果两边的优胜者相同，则他们的力量n就相加
        win = lwin;
        n = ln+rn;
    } else if(ln > rn){ // 如果两边的优胜者不同，则他们的力量n就相减
        win = lwin;
        n = ln-rn;
    } else{ // 如果两边的优胜者不同，则他们的力量n就相减
        win = rwin;
        n = rn-ln;
    }
}
```

main函数：
```
int majorityElement(vector<int>& nums) {
    if(nums.size() == 0) return -1;
    
    int win, n;
    div_con(nums, 0, nums.size(), win, n);
    return n>0 ? win : -1;
}
```
