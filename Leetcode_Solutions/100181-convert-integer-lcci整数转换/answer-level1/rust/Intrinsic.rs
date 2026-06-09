### 解题思路
x86 架构上有个 POPCNT 指令专门用来干这个的。

### 代码

```rust
impl Solution {
    pub fn convert_integer(a: i32, b: i32) -> i32 {
        #[cfg(target_arch = "x86")]
        use core::arch::x86::_popcnt32;

        #[cfg(target_arch = "x86_64")]
        use core::arch::x86_64::_popcnt32;

        unsafe { _popcnt32(a ^ b) }
    }
}
```