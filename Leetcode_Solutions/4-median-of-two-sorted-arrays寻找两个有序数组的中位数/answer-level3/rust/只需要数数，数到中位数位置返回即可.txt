1. 不需要合并数组，只需要数数
2. 数数时，注意区分，总数数目是奇数还是偶数即可
3. 若为奇数，数到一半即可跳出，偶数则要数两个。
PS：时间复杂度并未满足题目要求，这里是o(m+n).

```go
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var len1, i = len(nums1), 0
	var len2, j = len(nums2), 0
	var flag, b = 0, false
	if 0 == (len1+len2)%2 {
		flag = 1
	}
	var ans float64
	for k := 0; k < len1+len2; k++ {
		if b {
			break
		}
		if j == len2 || (i < len1 && j < len2 && nums1[i] < nums2[j]) {
			if flag == 1 && (k == (len1+len2)/2 || k == (len1+len2)/2-1) {
				ans += float64(nums1[i]) / 2.0
				if k == (len1+len2)/2 {
					b = true
				}
			} else if flag == 0 && k == (len1+len2)/2 {
				ans = float64(nums1[i])
				b = true
			}
			i++
			continue
		}
		if i == len1 || (i < len1 && j < len2 && nums2[j] <= nums1[i]) {
			if flag == 1 && (k == (len1+len2)/2 || k == (len1+len2)/2-1) {
				ans += float64(nums2[j]) / 2.0
				if k == (len1+len2)/2 {
					b = true
				}
			} else if flag == 0 && k == (len1+len2)/2 {
				ans = float64(nums2[j])
				b = true
			}
			j++
		}
	}

	return ans
}

```

```rust
#[allow(dead_code)]
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (len1, len2) = (nums1.len(), nums2.len());
        let mut ans = 0.0;
        let b = (len1 + len2) / 2;
        let (mut i, mut j) = (0, 0);
        for k in 0..b + 1 {
            if i == len1 || (i < len1 && j < len2 && nums1[i] >= nums2[j]) {
                if k == (len1 + len2 - 1) / 2 {
                    ans += nums2[j] as f64 / 2.0;
                }
                if k == (len1 + len2) / 2 {
                    ans += nums2[j] as f64 / 2.0;
                }
                j += 1;
            } else if j == len2 || (i < len1 && j < len2 && nums1[i] < nums2[j]) {
                if k == (len1 + len2 - 1) / 2 {
                    ans += nums1[i] as f64 / 2.0;
                }
                if k == (len1 + len2) / 2 {
                    ans += nums1[i] as f64 / 2.0;
                }
                i += 1;
            }
        }
        ans
    }
}
```