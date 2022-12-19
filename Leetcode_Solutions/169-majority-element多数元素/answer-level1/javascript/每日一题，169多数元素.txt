解题思路：
    首先，可以利用对象的键值不可重复的原理配合循环遍历来解决这一题，
        循环遍历过程中有一个小坑，害苦了我，仔细检查终于发现了，在第二次for-in循环的时候，前一次对的key值会被没有通过循环的key给
        覆盖，因此用一个变量接着就ok了。
    ps：第一次写，删掉了这个平台自定义的函数名，一直报错，机智的我，找了半天发现了5555~~~~~

代码如下：
        let nums = [3, 3, 4];
       
        var majorityElement = function (nums) {

            let number = {};
            for (let i = 0; i < nums.length; i++) {
                let value = nums[i];
                if (!number[value]) {
                    number[value] = 1;
                } else {
                    number[value]++;
                }
            }
            let max = 0;
            let max_value;
            for (const key in number) {
                if (number[key] > max) {
                    max = number[key];
                    console.log(max);
                    max_value = key;
                }
            }
            return max_value;

        };

        majorityElement(nums);