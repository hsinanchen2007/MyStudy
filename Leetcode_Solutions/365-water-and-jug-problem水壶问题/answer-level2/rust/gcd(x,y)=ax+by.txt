### 定理
对于不完全为0的非负整数`x,y`,gcd(x,y)表示 `x,y` 的最大公约数,必然存在整数对 `a,b`,使得 `gcd(x,y)=ax+by`

### 代码

```rust
impl Solution {
    pub fn can_measure_water(x: i32, y: i32, z: i32) -> bool {
        fn gcd (x: i32,y :i32)-> i32 {
            if x%y==0{
                return y
            }else{
                return gcd(y,x%y)
            }
        }
        x+y>=z  && !(x==0||y==0) &&z%gcd(x,y)==0 ||z==0   
    }
}
```