```
fun fullJustify(words: Array<String>, maxWidth: Int): List<String> {
          val list = arrayListOf<String>()
        var strBuilder: StringBuilder = StringBuilder()
        var subList = arrayListOf<String>()
        var startIndex = 0
        while (startIndex < words.size) {
            val str = words[startIndex] + " "
            //正好满足填满 不用填充空格
            if (strBuilder.length + words[startIndex].length == maxWidth) {
                strBuilder.append(words[startIndex])
                subList.add(words[startIndex])
                startIndex++
                list.add(strBuilder.toString())
                strBuilder.clear()
                subList.clear()
            }
            //小于宽度 继续填充
            else if (strBuilder.length + str.length <= maxWidth) {
                //已经是最后一个了
                if (startIndex == words.size - 1) {
                    strBuilder.append(words[startIndex])
                    while (strBuilder.length<maxWidth){
                        strBuilder.append(" ")
                    }
                    list.add(strBuilder.toString())
                    break
                }
                strBuilder.append(str)
                subList.add(str)
                startIndex++
            }
            //填充后超出宽度 计算空额填充位置
            else {
                var str=strBuilder.toString()
                if(str.endsWith(" ")){
                    str=str.substring(0,str.length-1)
                    subList[subList.lastIndex]=subList[subList.lastIndex].replace(" ","")
                }

                var space = maxWidth - str.length
                var spaceIndex = 0
                while (space > 0) {
                    if (spaceIndex >= subList.size-1) {
                        spaceIndex = 0
                    }
                    subList[spaceIndex] = subList[spaceIndex] + " "
                    spaceIndex++
                    space--
                }
                strBuilder.clear()
                for (item in subList) {
                    strBuilder.append(item)
                }
                list.add(strBuilder.toString())


                strBuilder.clear()
                subList.clear()
               // startIndex--
            }
        }
        return list
    }
```
