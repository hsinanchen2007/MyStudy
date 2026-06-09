js 中用list代替了java的hashmap, 不知道有没有别的方法替代


    function isValid(s) {
        // debugger
        let map = []

        let list = s.split('');
        for (let e of list) {
            if (isLeft(e)) {
                map.push(e)
            } else {
                //right
                let top = map[map.length - 1];
                if (match(top, e)) {
                    map.pop();
                } else {
                    return false;
                }
            }
        }
        if (map.length === 0)
            return true;
        else 
            return false
    }

    function isLeft(params) {
        return params === '(' || params === '{' || params === '[';
    }

    function match(a, b) {
        switch (a + b) {
            case '()':
                return true;
            case '[]':
                return true;
            case '{}':
                return true;
            default:
                return false;
        }
    }


执行结果
72 ms	34.1 MB