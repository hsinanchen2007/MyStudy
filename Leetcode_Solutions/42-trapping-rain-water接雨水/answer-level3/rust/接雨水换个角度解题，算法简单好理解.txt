解题思路：算法简单好理解
1. 先找出最高的
2. 然后扫描每一行
```
pub fn trap(height: Vec<i32>) -> i32 {
    let mut count = 0;
    let mut max = 0;
    for h in height.as_slice() {
        if *h > max{
            max = *h;
        }
    }
    for i in 0..max{
        let mut last = 0;
        let mut flag = false;
        for (j,h) in height.iter().enumerate(){
            if h > &(i as i32){
                if flag{
                    count = count +  j - last - 1;
                }
                last = j;
                flag = true;
            }
        }
        //println!("count:{}", count);
    }
    count as i32
}

```
