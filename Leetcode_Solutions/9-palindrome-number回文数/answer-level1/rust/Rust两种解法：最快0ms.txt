
![image.png](https://pic.leetcode-cn.com/06837a10c6487c32764260f01496cfc0e2a47e3ec34ce8585e590d117745a190-image.png)

解法两种，一是翻转整数后半部分，第二种是直接把x转换成string，然后再循环中从从头尾部两端开始，判断是否相等，不相等直接返回。
第一种方法根据测试用例不同，一般是0-4ms，第二种一般是8、12ms，内存消耗都是2m

方法一

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
       
        if x >= 0 && x<10{return true}
        if x < 0 || x%10 == 0 {return false}
        
        let mut x1:i32 = x;
        let mut half:i32 = 0;
      
       while true
    {
        if x1 <= half
        {
            break;
        }
        half = half *10 + x1 % 10;
        x1 = x1/10;
        
    }
      if x1 == half || x1 == half/10{return true}
        false
    }
}

方法二

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {return false}
        if x >= 0 && x<10{return true}
        
        let mut y;
        y = x.to_string();
        for i in 0..y.len()
    {
       if &y[i..i+1] == &y[y.len()-i-1..y.len()-i] 
       {
         if(i>y.len()-i-1){return true}
       }
       else
       {
        return false
       }
       
    }
        true
    }
}