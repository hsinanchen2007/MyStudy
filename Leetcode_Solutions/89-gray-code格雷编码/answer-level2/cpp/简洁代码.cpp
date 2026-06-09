```
vector<int> grayCode(int n) {
    vector<int> ans{0};
    int cnt = 1; //记录数组长度
    while(n--){
        // 最高位加0，就是上一轮的数组，不用改动
        // 倒序最高位加1
        for(int i = cnt - 1;i >= 0;i--) ans.emplace_back(ans[i] + cnt); 
        cnt <<= 1;
    }
    
    return ans;
}
```

