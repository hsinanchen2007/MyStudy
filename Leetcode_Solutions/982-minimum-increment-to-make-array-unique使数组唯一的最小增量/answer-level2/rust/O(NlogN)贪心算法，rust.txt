```rust
fn min_increment_for_unique(a: Vec<i32>) -> i32 {
  let mut mut_a:Vec<i32> =a.clone();
  mut_a.sort();
  let mut pre=-1;
  let mut cnt=0;
  mut_a.iter().for_each(|&x|{
    if x<=pre{
      cnt+=pre+1-x;
      pre=pre+1;
    }else{
      pre=x;
    }
  });
  cnt
}
```

用到了简单的贪心算法，先对数组a拷贝，再进行排序，遍历排序后的数组，找到每个数达到unique需要move的次数。完毕。