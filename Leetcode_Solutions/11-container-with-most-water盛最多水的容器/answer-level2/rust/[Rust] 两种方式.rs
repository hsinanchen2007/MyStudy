# 方式不同，消耗的资源不同

# 方式1：暴力
*300ms左右/2m左右*
```
pub fn max_area(height: Vec<i32>) -> i32 {
        let compute_area = |min_height: i32, step: i32| -> i32 { min_height * step };
        let min_value = |a: i32, b: i32| -> i32 { if a > b { b } else { a } };
        let mut max_area = 0_i32;
        for (i, n) in height.iter().enumerate() {
            let mut j = i + 1;
            while let Some(&j_value) = height.get(j) {
                if let Some(&i_value) = height.get(i) {
                    let temp = compute_area(min_value(i_value, j_value), (j - i) as i32);
                    if temp > max_area { max_area = temp }
                }
                j += 1;
            }
        }
        max_area
    }
```

# 方式2：双指针
*0ms左右/2m左右*
```
pub fn max_area(height: Vec<i32>) -> i32 {
        let compute_area = |min_height: i32, step: i32| -> i32 { min_height * step };
        let min_value = |a: i32, b: i32| -> i32 { if a > b { b } else { a } };
        let mut max_area = 0_i32;
        let (mut i, mut j, mut i_value, mut j_value): (usize, usize, i32, i32) = (0, height.len() - 1, 0, 0);
        while (i < j) {
            i_value = *height.get(i).unwrap();
            j_value = *height.get(j).unwrap();
            let temp  = compute_area(min_value(i_value, j_value), (j-i) as i32);
            if temp > max_area { max_area = temp }
            if i_value <= j_value {
                i += 1
            } else {
                j -= 1;
            }

        }
        max_area
    }
```
