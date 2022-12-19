/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length != t.length)    return false;

    let arr_1 = s.split("");
    let arr_2 = t.split("");

    let dic1 = new Map();
    let dic2 = new Map();
    //累计每个字母出现的次数，完成的形式应该是{ "a" => 3, "n" => 1...}一样的.
    for(let item in arr_1){
        dic1.set(arr_1[item], (dic1.get(arr_1[item]) || 0) + 1);
    }
    //这个也是累计每个字母出现的次数，完成的形式应该是{  "n" => 1， “a" => 3...}一样的.
    for(let item in arr_2){
        dic2.set(arr_2[item], (dic2.get(arr_2[item]) || 0) + 1);
    }
    //判断两个hash是否相等
    for(let [key, value] of dic1){
        if(!dic2.has(key) || dic2.get(key) != value){
            return false;
        }
    }
    return true;
};

