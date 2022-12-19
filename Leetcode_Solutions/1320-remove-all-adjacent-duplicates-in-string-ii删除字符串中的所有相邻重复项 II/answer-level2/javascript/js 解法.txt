var removeDuplicates = function(s, k) {
    // 删除操作
    let arr = [];
    for (let i = 0; i < s.length; i++) {
        if (!arr.length) {
            arr.push(`${s[i]}-1`)
        } else {
            let last = arr[arr.length - 1];
            if (last[0] !== s[i]) {
                arr.push(`${s[i]}-1`)
            } else {
                const num = parseInt(last.split("-")[1]);
                if (num + 1 === k) {
                    arr.pop();
                } else {
                    arr[arr.length - 1] = `${s[i]}-${num + 1}`;
                }
            }
        }
    }
    
    // 拼装字符串
    let str = "";
    arr.map(item => {
        const itemArr = item.split("-");
        for (let i = 0; i < itemArr[1]; i++) {
            str += itemArr[0];
        }
    })

    return str;
};