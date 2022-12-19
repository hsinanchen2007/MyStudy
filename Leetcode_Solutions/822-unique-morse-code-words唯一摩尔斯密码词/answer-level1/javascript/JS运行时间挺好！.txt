
```
var uniqueMorseRepresentations = function(words) {
    function switchSomething (val) {
        switch(val){
            case 'a':
                return ".-"
            case 'b':
                return "-..."
            case 'c':
                return "-.-."
            case 'd':
                return "-.."
            case 'e':
                return "."
            case 'f':
                return "..-."
            case 'g':
                return "--."
            case 'h':
                return "...."
            case 'i':
                return ".."
            case 'j':
                return ".---"
            case 'k':
                return "-.-"
            case 'l':
                return ".-.."
            case 'm':
                return "--"
            case 'n':
                return "-."
            case 'o':
                return "---"
            case 'p':
                return ".--."
            case 'q':
                return "--.-"
            case 'r':
                return ".-."
            case 's':
                return "..."
            case 't':
                return "-"
            case 'u':
                return "..-"
            case 'v':
                return "...-"
            case 'w':
                return ".--"
            case 'x':
                return "-..-"
            case 'y':
                return "-.--"
            case 'z':
                return "--.."                                                                                                        
        }
    }
    var arr = []
    var arrNew = []
    for(var i=0; i<words.length; i++){
        var item = words[i].split('')
        arr.push(item)
    }
    for(var i=0; i<words.length; i++){
        var add = 0
        for(var j=0;j<words[i].length; j++){
            add+=switchSomething(words[i][j])
        }
        arrNew.push(add)
    }
    var arrNum = []
    for(var i=0; i<arrNew.length; i++){
        if(arrNum.indexOf(arrNew[i]) == -1){
            arrNum.push(arrNew[i])
        }
    }
    return arrNum.length
};
```
switch展示了......毅力......运行时间还是挺好看的~
