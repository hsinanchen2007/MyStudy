困难题目真的有点费劲啊，
最重要的是增加一个缓存的定时器，put和get都增加就好了

```
struct LFUCache {
    timer:i32,
    data:Vec<(i32,i32,i32,i32)>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LFUCache {

    fn new(capacity: i32) -> Self {
        Self{timer:0, data:Vec::with_capacity(capacity as usize)}
    }
    
    fn get(&mut self, key: i32) -> i32 {
        let mut value = -1;
        if self.data.capacity() == 0{
            return value;
        }
        for node in &mut self.data{
            if node.0 == key{
                self.timer += 1;
                node.2 += 1;
                node.3 = self.timer;
                value = node.1;
            }
        }
        //println!("{:?}", self.data);
        return value;
    }
    
    fn put(&mut self, key: i32, value: i32) {
        if self.data.capacity() == 0{
            return;
        }
        //let mut finded = false;
        for node in &mut self.data{
            if node.0 == key{
                self.timer += 1;
                node.1 = value;
                node.2 += 1;
                node.3 = self.timer;
                return;
            }
        }
        if self.data.len() == self.data.capacity(){
            let mut idx = 0;
            let (mut used, mut times) = (self.data[0].2,self.data[0].3);
            for (i, node) in self.data.iter().enumerate(){
                if node.2 < used{
                    used = node.2;
                    times = node.3;
                    idx = i;
                } else if node.2 == used {
                    if node.3 < times{
                        used = node.2;
                        times = node.3;
                        idx = i;
                    }
                }
            }
            self.data.remove(idx);
            //println!("remove:{}-{:?}", idx, self.data);
        }
        let node = (key, value, 0, 0);
        self.data.push(node);
        //println!("{:?}", self.data);
    }
}

```
