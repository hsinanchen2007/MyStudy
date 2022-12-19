基本思路：矩形区域内点离圆心最近的点距离小于等于圆的半径  


矩形区域特点是```x```,```y```取值相互独立  
又距离公式对```x```,```y```分别单调  
分别取最小距离即可  

又由 ```x1 < x2``` , ```y1 < y2``` 可以简化最小距离获取过程  
对于 x 
```x_center < x1 < x2```    =>```min(dx) = x1 - x_center```  
```x1 <= x_center <= x2```  =>```min(dx) = 0```  
```x1 < x2 < x_center```    =>```min(dx) = x_center - x2```  
对于 y 同理


```javascript []
/**
 * @param {number} radius
 * @param {number} x_center
 * @param {number} y_center
 * @param {number} x1
 * @param {number} y1
 * @param {number} x2
 * @param {number} y2
 * @return {boolean}
 */
var checkOverlap = function (radius, x_center, y_center, x1, y1, x2, y2) {
    var dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
    var dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
    return dx * dx + dy * dy <= radius * radius;
};
```
```cpp []
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
        int dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
        return dx * dx + dy * dy <= radius * radius;
    }
};
```
```c []
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
    int dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
    return dx * dx + dy * dy <= radius * radius;
}
```
```java []
class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
        int dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
        return dx * dx + dy * dy <= radius * radius;
    }
}
```
```csharp []
public class Solution {
    public bool CheckOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
        int dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
        return dx * dx + dy * dy <= radius * radius;
    }
}
```
```py []
class Solution(object):
    def checkOverlap(self, radius, x_center, y_center, x1, y1, x2, y2):
        """
        :type radius: int
        :type x_center: int
        :type y_center: int
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :rtype: bool
        """
        dx = x1 - x_center if x1 > x_center else x_center - x2 if x_center > x2 else 0 
        dy = y1 - y_center if y1 > y_center else y_center - y2 if y_center > y2 else 0 
        return dx * dx + dy * dy <= radius * radius

```
```python3 []
class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:        
        dx = x1 - x_center if x1 > x_center else x_center - x2 if x_center > x2 else 0 
        dy = y1 - y_center if y1 > y_center else y_center - y2 if y_center > y2 else 0 
        return dx*dx + dy*dy <= radius*radius
```
```golang []
func checkOverlap(radius int, x_center int, y_center int, x1 int, y1 int, x2 int, y2 int) bool {
    var dx, dy int;
    if x1 > x_center {
        dx = x1 - x_center  
    }else if x_center > x2 {
        dx = x_center - x2 
    }else {
        dx = 0
    }
    if y1 > y_center {
        dy = y1 - y_center  
    }else if y_center > y2 {
        dy = y_center - y2 
    }else {
        dy = 0
    }
    return dx * dx + dy * dy <= radius * radius
}
```
```ruby []
# @param {Integer} radius
# @param {Integer} x_center
# @param {Integer} y_center
# @param {Integer} x1
# @param {Integer} y1
# @param {Integer} x2
# @param {Integer} y2
# @return {Boolean}
def check_overlap(radius, x_center, y_center, x1, y1, x2, y2)
    dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
    dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
    return dx * dx + dy * dy <= radius * radius;
end
```
```swift []
class Solution {
    func checkOverlap(_ radius: Int, _ x_center: Int, _ y_center: Int, _ x1: Int, _ y1: Int, _ x2: Int, _ y2: Int) -> Bool {
        let dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
        let dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
        return dx * dx + dy * dy <= radius * radius;
    }
}
```
```scala []
object Solution {
    def checkOverlap(radius: Int, x_center: Int, y_center: Int, x1: Int, y1: Int, x2: Int, y2: Int): Boolean = {
        val dx = if (x1 > x_center) x1 - x_center else if (x_center > x2) x_center - x2 else 0 
        val dy = if (y1 > y_center) y1 - y_center else if (y_center > y2) y_center - y2 else 0 
        return dx*dx + dy*dy <= radius*radius
    }
}
```
```kotlin []
class Solution {
    fun checkOverlap(radius: Int, x_center: Int, y_center: Int, x1: Int, y1: Int, x2: Int, y2: Int): Boolean {
        val dx = if (x1 > x_center) x1 - x_center else if (x_center > x2) x_center - x2 else 0 
        val dy = if (y1 > y_center) y1 - y_center else if (y_center > y2) y_center - y2 else 0 
        return dx*dx + dy*dy <= radius*radius
    }
}
```
```rust []
impl Solution {
    pub fn check_overlap(radius: i32, x_center: i32, y_center: i32, x1: i32, y1: i32, x2: i32, y2: i32) -> bool {
        let dx = if (x1 > x_center) {x1 - x_center} else if (x_center > x2) {x_center - x2} else {0};
        let dy = if (y1 > y_center) {y1 - y_center} else if (y_center > y2) {y_center - y2} else {0};
        return dx*dx + dy*dy <= radius*radius;
    }
}
```
```php []
class Solution {

    /**
     * @param Integer $radius
     * @param Integer $x_center
     * @param Integer $y_center
     * @param Integer $x1
     * @param Integer $y1
     * @param Integer $x2
     * @param Integer $y2
     * @return Boolean
     */
    function checkOverlap($radius, $x_center, $y_center, $x1, $y1, $x2, $y2) {
        $dx = ($x1 > $x_center) ? ($x1 - $x_center) : (($x_center > $x2) ? ($x_center - $x2) : 0);
        $dy = ($y1 > $y_center) ? ($y1 - $y_center) : (($y_center > $y2) ? ($y_center - $y2) : 0);
        return (($dx * $dx + $dy * $dy) <= $radius * $radius);
    }
}
```