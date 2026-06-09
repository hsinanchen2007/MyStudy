### 解题思路
    /*
     * 方法1 暴力法 O(max(sqrt(candies), num_people))
     *
     * 直接遍历糖果数组，当有糖时就分给小孩，
     * 当糖不够时就分给最后一个小孩，当糖为0时分发停止。
     *
     * 方法2 等差数列法 虽然等差数列法很好，但是公式总结很麻烦，
     * 最后的时间复杂度为O(n)，具体看官方题解
     * (https://leetcode-cn.com/problems/distribute-candies-to-people/solution/fen-tang-guo-ii-by-leetcode-solution/)
     * */
### 代码
```cpp
std::vector<int> distributeCandies(int candies, int num_people) {
    std::vector<int> ans(num_people, 0);
    int count = 0;

    // 当还有糖时，就不断分发
    while (candies != 0){
        // 取num_people的余数对每个小孩的糖进行叠加
        // 当糖一直大于count时，就将count颗糖分给当前小孩
        // 当糖小于count时，就将剩下的糖全给当前小孩
        ans[count % num_people] += std::min(candies, count+1);

        // 将糖减去分发出去的部分，
        // 最后将小于count的糖全部分给当前小孩，停止分发
        candies -= std::min(candies, count+1);
        count++;
    }

    return ans;
}
```