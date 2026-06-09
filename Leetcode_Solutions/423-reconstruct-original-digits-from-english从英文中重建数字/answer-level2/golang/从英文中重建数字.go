#### 思路

其实是一道找规律的题

    zero                z
    one 
    two                 w
    three
    four                u
    five            
    six                 x
    seven
    eight               g
    nine
    
    上面标出来的字符, 就是唯一的字符, 若字符串s中找到一个z说明有一个zero. 同理可得 two four six eight. 
    
    之后就是找规律了, 通过已知条件求未知条件。
    
    three字符中, 可以通过已知条件求出来的字符是t, 因为除了three外, 包含t的字符只有 eight 和 two , 恰好eight和two的个数我们可以通过唯一字符w和g得出。
    所以three出现的概率为 t字符出现的次数减去2出现的个数和8出现的个数。
    
    一步一步通过已知条件求未知条件, 找出答案就是时间问题了。
    
    
#### code


```
func originalDigits(s string) string {
    m := make(map[byte]int)
    for i := 0; i < len(s); i++ {
        m[s[i]]++
    }
    nums := make([]int, 10)
    nums[0] = m['z']
    nums[2] = m['w']
    nums[4] = m['u']
    nums[6] = m['x']
    nums[8] = m['g']
    nums[3] = m['t']-nums[2]-nums[8]
    nums[1] = m['o']-nums[0]-nums[2]-nums[4]
    nums[7] = m['s']-nums[6]
    nums[5] = m['v']-nums[7]
    nums[9] = m['i']-nums[5]-nums[6]-nums[8]
    
    res := []byte{}
    for i := 0; i < 10; i++ {
        for j := 0; j < nums[i]; j++ {
            res = append(res, byte(i)+'0')
        }
        
    }
    return string(res)
}
```