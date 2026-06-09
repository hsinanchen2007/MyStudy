### 解题思路
abs（）函数耗能太大了，这里没有用。

### 代码

```swift
class Solution {
    func findRadius(_ houses: [Int], _ heaters: [Int]) -> Int {

        //因为发现测试用例中存在houses和heaters乱序排列的情况（有病吧？）所以先对两个输入数组排序
        let houses = houses.sorted()
        let heaters = heaters.sorted()
        
        //初始化左边和右边暖炉的坐标
        var leftHeaterPosition = 0
        var rightHeaterPosition = 0
        
        //返回值
        var result = 0
        
        //遍历房屋
        for house in houses {
            
            //初始化离每间屋子最近的暖炉的距离
            var distanceOfHouseToNearestHeater = 0
            
            //滑动查找不断更新离每间屋子最近的左边和右边暖炉的坐标
            while house >= heaters[rightHeaterPosition] && rightHeaterPosition + 1 < heaters.count {
                
                leftHeaterPosition = rightHeaterPosition
                rightHeaterPosition += 1
                
            }
            
            //如果房子离最左边的暖炉还要左，则离它最近的暖炉距离就是它与最左边那个暖炉的距离
            if house <= heaters[leftHeaterPosition] {
                distanceOfHouseToNearestHeater = heaters[leftHeaterPosition] - house
            }//如果房子左右两边都有暖炉，则离它最近的暖炉的距离就是它分别与两个暖炉直接距离的最小值
            else if house > heaters[leftHeaterPosition] && house < heaters[rightHeaterPosition] {
                distanceOfHouseToNearestHeater = min(house - heaters[leftHeaterPosition], heaters[rightHeaterPosition] - house)
            }//如果房子离最右边的暖炉还要右，则离它最近的暖炉的距离就是它与最右边那个暖炉的距离
            else if house >= heaters[rightHeaterPosition] {
                distanceOfHouseToNearestHeater = house - heaters[rightHeaterPosition]
            }

            //每次更新返回值
            result = max(result, distanceOfHouseToNearestHeater)
        }
        
        
        return result
    }
}
```