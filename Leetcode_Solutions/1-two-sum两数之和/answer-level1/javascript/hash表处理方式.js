### 解题思路
使用hash表的方式，对数据进行hash对象处理，在hash处理的时候为了不增加数据碰撞概率，对数据进行以

### 代码

```javascript
       /**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    /**
     * 使用hash表的方式，对数据进行hash对象处理，在hash处理的时候为了不增加数据碰撞概率，对数据进行以      * 下处理
     * 1.便利数据保证数据进行充分的处理，处理点是num= shi*shi_num + ge_num,
     * dict={
     *  'shi_num':[{
     *  number:num,
     *  shi_num: ,//10位数据
     *  ge_num: ,//各位数据
     *  shi_num: "",
     *  arr_key:""
     *  key:index,
     *  othernum:,
     *  otherkey:
     * }]
     * }
     * 查找数据时nums_ge_num[shi_num +ge_num] ={
     *  nums=,
     *  key=,
     *  othernum=,
     *  otherkey=
     * }
     */
    let sums=[]
    let dict={}
    for(let index=0;index<nums.length;index++) {
        // 1.处理数据
        let it = getNumber(index,nums[index],target,dict)
        if(!it) continue
        if(it.other_index && it.other_index!==it.key) {
            sums.push(it.other_index)
            sums.push(it.key)
            return sums
        }
        if(dict[it.shi_num.toString()]) {
            if(dict[it.shi_num.toString()][it.ge_num] && !isNaN(it.other_index) && it.key !== dict[it.shi_num.toString()][it.ge_num].other_index) {
                if(it.number === it.othernum) {
                    sums.push(it.other_index)
                    sums.push(it.key)
                    return sums
                } else{
                    debugger
                    sums.push(dict[it.shi_num.toString()][it.ge_num].other_index)
                    sums.push(it.key)
                    return sums
                }
            } else{
                dict[it.shi_num.toString()][it.ge_num] = it
            }
        } else{
            dict[it.shi_num.toString()] = []
            dict[it.shi_num.toString()][it.ge_num]=it
        }
    }
    
    return sums
};

function getNumber(index,num,target,dict) {
    let shiNum = parseInt(num/10)
    let geNum = num %10
    let div = target-num
    let otherShiNum= parseInt(div/10)
    let othetGeNum= div%10
    // 对other进行处理
    let other_i
    if(dict[otherShiNum.toString()]) {
        let i =dict[otherShiNum.toString()][othetGeNum]
        if(dict[otherShiNum.toString()][othetGeNum]){
            other_i = parseInt(dict[otherShiNum.toString()][othetGeNum].key)
        } else{
            dict[otherShiNum.toString()][othetGeNum]= {
                'number': div,
                'shi_num': otherShiNum,
                'ge_num':othetGeNum,
                'key': null,
                'othernum': num,
                "other_shi_num": shiNum,
                "other_ge_num": geNum,
                "other_index": index
            }
        }
    } else{
        dict[otherShiNum.toString()] = []
        dict[otherShiNum.toString()][othetGeNum] = {
                'number': div,
                'shi_num': otherShiNum,
                'ge_num':othetGeNum,
                'key': null,
                'othernum': num,
                "other_shi_num": shiNum,
                "other_ge_num": geNum,
                "other_index": index
            }
    }
    let objs = {
        'number': num,
        'shi_num': shiNum,
        'ge_num':geNum,
        'key': index,
        'othernum': div,
        "other_shi_num": otherShiNum,
        "other_ge_num": othetGeNum,
        "other_index": other_i
    }
    return objs
}
```