### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn gcd(a: i32,b: i32) -> i32 {
        if a % b==0 {
            return b;
        }else{
            return Solution::gcd(b,a % b);
        }
    }
    pub fn can_measure_water(x: i32, y: i32, z: i32) -> bool {
        if x + y < z {
            return false;
        }
        if x==0 || y==0 {
            return z==0 || x+y==z;
        }
        z%Solution::gcd(x,y) == 0
    }
}

```