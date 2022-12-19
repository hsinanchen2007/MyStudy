根据规律发现可以找到但凡非快乐数都会出现4即陷入一个循环,因此只需要循环,如果发现非快乐数(以4为头开始的一串数字)或者发现和为1即可跳出循环,Rust解法不改变所给框架条件下不可使用递归,因此采用了loop循环进行模拟递归
```
impl Solution 
{
    pub fn is_happy(n: i32) -> bool 
    {
        let vec = vec![4,16,37,58,89,145,42,20];
        let mut z = n;
        loop
        {
        let mut flag = 0;
        for i in 0..7
        {
            if z==vec[i]
            {
                return false;
            }
        }
        loop
        {
            flag += (z%10)*(z%10);
            z /= 10;
            if z <= 0
            {
                break;
            }
        }
        if flag == 1
        {
            return true;
        }
        z = flag;
        }
    }
}
```
