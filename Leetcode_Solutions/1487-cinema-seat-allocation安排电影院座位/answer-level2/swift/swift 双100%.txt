这个题目有两个注意点
1:不需要遍历n，遍历n很容易就TLE。
2：假如某一行没有被买过票,其实这一行最多能凑2个家庭

主要思路：假如所有的座位都是空的,那么总共就只有total = 2*n 种情况。然后处理那些不是空的行,假如某一行实际能够满足条件的家庭数为act_total,那么总数total=total-2+act_total，因为最开始这一行计算了2，所以减掉2加上act_total就是实际的总数。
1：用一个 Dictionary<Int, [Int]> 来存作为数据,将数据按照行号分组
2：遍历 dict,来处理每一行实际的数量,假如某一行第1个作为和第10个座位被占用了，那么初始化一个数组[0,1,1,1,1,1,1,1,1,0],0表示被占用了,1表示没有被占用,通过这个数据来统计能够满足条件的家庭数，就是函数calculateCount。

    class Solution {
        func maxNumberOfFamilies(_ n: Int, _ reservedSeats: [[Int]]) -> Int {
            var res = 0
            var dict: Dictionary<Int, [Int]> = Dictionary<Int,[Int]>()
            for element in reservedSeats {
                var list = dict[element[0]]
                if (list == nil){
                    list = [Int]()
                }
                list!.append(element[1])
                dict[element[0]] = list
            }
            res = 2*n
            for (_, seatList) in dict {
                var rowSeats: [Int] = [Int](repeating: 1, count: 10)
                for element in seatList {
                    rowSeats[element-1] = 0
                }
                //计算这一行实际的数量
                res = res - 2 + calculateCount(rowSeats)
            }
            return res
        }
    
        func calculateCount(_ list: [Int]) -> Int {
            var count = 0
            //判断1，2，3，4是否满足条件
            if (isTrue(1, 4, list)){
                count = count + 1
                if (isTrue(5, 8, list)){
                    count = count + 1
                }
            }else{
                if (isTrue(3, 6, list)){
                    count = count + 1
                }else{
                    if (isTrue(5, 8, list)){
                        count = count + 1
                    }
                }
            }
            return count
        }
    
    //用来判断在[start, end]之间,是否全部为1
        func isTrue(_ start: Int, _ end: Int, _ list: [Int]) -> Bool {
            for index in start..<end+1 {
                if (list[index] == 0){
                    return false
                }
            }
            return true
        }
    }