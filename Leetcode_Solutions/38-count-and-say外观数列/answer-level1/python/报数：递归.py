![image.png](https://pic.leetcode-cn.com/cc56acf05116ce0251a5dcc33e9194c7e181e0a4e19f80b7a2d714d1ae73f2f5-image.png)


```
        if n == 1: return '1'
        
        previous_ = '1'
        for i in range(1, n):
            next_ = ''
            num = previous_[0]
            count = 1
            for j in range(1, len(previous_)):
                
                if previous_[j] == num:
                    count += 1
                else:
                    next_ += (str(count) + num)
                    num = previous_[j]
                    count = 1
                
            next_ += (str(count) + num)
            previous_ = next_
            
        return next_
```