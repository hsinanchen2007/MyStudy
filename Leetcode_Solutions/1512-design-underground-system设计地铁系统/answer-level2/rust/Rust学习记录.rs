### 解题思路

使用HashMap构造抽象，解决问题（解法可以参考注释）
易错点为HashMap容易用用户id来作为键，实际上同一个用户可能多次乘坐地铁，这种情况下就只能完成第一次的记录。

### 代码

```rust
use std::collections::HashMap;


struct user_in {
    in_time:i32,
    in_station:String,
    
}
struct user_out {
    out_time:i32,
    out_station:String
    
}
struct UndergroundSystem {
    user_in_map:HashMap<Vec<i32>,user_in>,
    user_out_map:HashMap<Vec<i32>,user_out>
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl UndergroundSystem {

    fn new() -> Self {
        UndergroundSystem {
            user_in_map: HashMap::new(),
            user_out_map: HashMap::new(),
        }
        
    }
    
    /*
        the enter function, 
        the fn add a enter record to user_in_map
        one user could enter for serveal times , check if there is enter before ,record the frequency
        use 0..100 to record frequency,better use loop or add a number to record the total times
    */
    fn check_in(&mut self, id: i32, station_name: String, t: i32) {
        for i in 0..100 {
            if  match self.user_in_map.get(&vec![id,i]) {
                    Some(_) => false,
                    None => true,
                }  {
                self.user_in_map.insert(vec![id,i],user_in{
                    in_time:t,
                    in_station:station_name,
                });
                break;
            }
            
        }
    }
    
        /*
        the leave function, 
        the fn add a check out record to user_in_map
        one user could leave for serveal times , check if there is enter before ,record the frequency
        use 0..100 to record frequency,better use loop or add a number to record the total times
    */
    fn check_out(&mut self, id: i32, station_name: String, t: i32) {
            for i in 0..100 {
                if match self.user_out_map.get(&vec![id,i]) {
                    Some(_) => false,
                    None => true,
                }  {
                self.user_out_map.insert(vec![id,i],user_out{
                    out_time:t,
                    out_station:station_name,
                });
                break;
            }
            }
    }
    
    /*
        reval the out_map(it confirms the record is complete),if matches the path we want
        record the length and increase the count
    */
    fn get_average_time(&self, start_station: String, end_station: String) -> f64 {
        let mut count:i64 = 0;
        let mut sum:i64 = 0;
        for (k,v) in &self.user_out_map {
            if v.out_station == end_station && self.user_in_map.get(k).unwrap().in_station == start_station {
                sum = sum + (v.out_time - self.user_in_map.get(k).unwrap().in_time) as i64;
                count = count + 1;
                
            }
        }
        if count == 0 {
            return 0.0f64;
        }
        (sum as f64 / count as f64)

    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * let obj = UndergroundSystem::new();
 * obj.check_in(id, stationName, t);
 * obj.check_out(id, stationName, t);
 * let ret_3: f64 = obj.get_average_time(startStation, endStation);
 */
```