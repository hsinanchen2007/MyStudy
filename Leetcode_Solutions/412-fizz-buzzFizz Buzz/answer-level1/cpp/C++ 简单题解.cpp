![image.png](https://pic.leetcode-cn.com/06e20c99afee3b359d65acd50387c4d58b4165506e4783b7bb22331aa8abc7b2-image.png)
解题思路：很简单的四个判断。
```
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1;i <= n;++i){
            if(i%15 == 0) res.push_back("FizzBuzz");
              else if(i%3 == 0) res.push_back("Fizz");
                  else if(i%5 == 0) res.push_back("Buzz");
                      else res.push_back(to_string(i));
        }
        return res;
    }
```

