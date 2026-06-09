```
impl Solution {
    pub fn days_between_dates(date1: String, date2: String) -> i32 {
        let year1:i32 = date1[0..4].to_string().parse().expect("");
        let year2:i32 = date2[0..4].to_string().parse().expect("");
        let month1:i32 = date1[5..7].to_string().parse().expect("");
        let month2:i32 = date2[5..7].to_string().parse().expect("");
        let day1:i32 = date1[8..10].to_string().parse().expect("");
        let day2:i32 = date2[8..10].to_string().parse().expect("");
        
        // println!("year1: {}, year2: {}, month1: {}, month2: {}, day1: {}, day2: {}", year1, year2, month1, month2, day1, day2);
        
        let mut month = vec![31,28,31,30,31,30,31,31,30,31,30,31];
        
        let mut days1 = 0;
        let mut days2 = 0;

        for i in 1970..year1 {
            if (i % 4 == 0 && i % 100 != 0) || i % 400 == 0 {
                days1 += 366;
            }else {
                days1 += 365;
            }
        }
        
        for i in 1..month1 {
            if i == 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
                days1 += 1;
            }
            days1 += month[(i-1) as usize];
        }
        
        days1 += day1;
        
        for i in 1970..year2 {
            if i % 4 == 0 && i % 100 != 0 || i % 400 == 0 {
                days2 += 366;
            }else {
                days2 += 365;
            }
        }
        
        for i in 1..month2 { 
            if i == 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
                days2 += 1;
            }
            days2 += month[(i-1) as usize];
        }
        
        days2 += day2;
        
        (days1 -days2).abs() 
    }
}
```
![image.png](https://pic.leetcode-cn.com/dcd15b3a4f7c21b5c8e323d3604027f029e6e8bd5196a81d9e91033397d5d45b-image.png)
注意闰年的定义
