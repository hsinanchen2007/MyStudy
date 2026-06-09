暴力模拟，一个一个向右移动，O(nk)时间，O(1)空间
```
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len() as i32;
        let k = (k % len);
        let len = len as usize;
        for _ in 0..k {
            let last = nums[len-1];
            for i in (1..len).rev() {
                nums[i] = nums[i-1];
            } 
            nums[0] = last;
        }
    }
}
```

直接取出后几个元素，放在左边，O(n)时间，O(n)空间
```
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len() as i32;
        let k = k % len; 
        let k = (len - k) as usize;
        let mut last_k = nums.split_off(k);
        last_k.append(nums);
        *nums = last_k;
    }
}

先翻转整个数组，再分别翻转前一半和后一半，O(n)时间，O(1)空间
```
impl Solution {
    fn reverse(nums: &mut Vec<i32>, mut l: i32, mut r:i32) {
        while l<r {
            nums[l as usize] ^= nums[r as usize];
            nums[r as usize] ^= nums[l as usize];
            nums[l as usize] ^= nums[r as usize];
            l+=1;
            r-=1;
        }
    }

    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len() as i32;
        let k = (k % len);
        let mut s1len = k;

        Self::reverse(nums,0,len-1);
        Self::reverse(nums,0,s1len-1);
        Self::reverse(nums,s1len,len-1);

    }
}
```

分组环状替换，O(n)时间，O(1)空间
```
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len();
        let k = k as usize % len;
        let mut count = 0;

        for start in (0..k) {
            let mut current = start;
            let mut prev = nums[current];
            loop {
                current = (current+k)%len;
                let temp = nums[current];
                nums[current] = prev;
                prev = temp;
                count += 1;
                if current == start {
                    break;
                }
            }
            if count == len {
                break;
            }
        }

    }
}
```
