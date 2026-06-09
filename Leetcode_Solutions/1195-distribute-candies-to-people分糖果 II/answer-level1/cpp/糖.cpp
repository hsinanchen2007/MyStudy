为啥我用的空间总是那么多?

![image.png](https://pic.leetcode-cn.com/2178af84d421e994f37d6101dc367912f11112884000272aa3180ef12010484a-image.png)


```
vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ans(num_people, 0);
    for(int i=0; candies>0; i++){
        if(candies-i-1>=0){
            ans[i%num_people] += i+1;
            candies -= i+1;
        } else {
            ans[i%num_people] += candies;
            candies -= candies;
        }
    }
    return ans;
}
```
