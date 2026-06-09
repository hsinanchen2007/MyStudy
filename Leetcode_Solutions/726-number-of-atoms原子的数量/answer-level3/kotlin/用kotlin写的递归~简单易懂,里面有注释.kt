## 没有任何难度的解法,就是递归

读题已知下面三个点:

1. 所有元素都是大写字母开头
2. 有括号需要计算
3. 字典排序

解决方式:

1. 寻找元素str,找到所有可能结束元素的方式
    -. 大写字母
    -. 左括号
    -. 右括号
2. 发现左括号后进行递归,发现右括号后进行弹出
3. 利用TreeMap自动进行字典排序

注意点:

1. 数字可能是多位的,循环char的时候要小心

````Kotlin

import java.util.*

//各个char元素对应的Int
//A-Z byte:65-90
//0-9 byte:48-57
//a-z byte:97-122
//(-) byte:40-41
class Solution {
    fun countOfAtoms(formula: String): String {
        val formulaChars = formula.toCharArray()
        val result = loopGetString(formulaChars.iterator())
        val resultString = StringBuilder()
        result.forEach {
            if (it.value != 1) {
                resultString.append(it.key)
                resultString.append(it.value)
            } else {
                resultString.append(it.key)
            }
        }
        return resultString.toString()
    }


    fun loopGetString(formulaCharsIterator: Iterator<Char>): TreeMap<String, Int> {
        //当前循环已经分析完成的元素
        val currentElements = TreeMap<String, Int>()

        //正在添加的元素
        val stringBuilder = StringBuilder()
        //当前的倍数
        var currentMulti: String? = null
        //括号内的元素
        val parenthesesElements = TreeMap<String, Int>()
        //循环获取所有字符
        while (formulaCharsIterator.hasNext()) {
            val nextChar = formulaCharsIterator.next()
            when (nextChar.toInt()) {
                in 65..90 -> {
                    calculateAndAddElement(
                        stringBuilder,
                        currentMulti,
                        currentElements,
                        parenthesesElements
                    )
                    currentMulti = null
                    stringBuilder.append(nextChar)
                }
                in 48..57 -> currentMulti = (currentMulti ?: "") + nextChar
                in 97..122 -> stringBuilder.append(nextChar)
                40 -> {
                    calculateAndAddElement(
                        stringBuilder,
                        currentMulti,
                        currentElements,
                        parenthesesElements
                    )
                    currentMulti = null
                    parenthesesElements.putAll(loopGetString(formulaCharsIterator))
                }
                41 -> {
                    calculateAndAddElement(
                        stringBuilder,
                        currentMulti,
                        currentElements,
                        parenthesesElements
                    )
                    return currentElements
                }
            }
        }
        calculateAndAddElement(
            stringBuilder,
            currentMulti,
            currentElements,
            parenthesesElements
        )
        return currentElements
    }

    private fun calculateAndAddElement(
        stringBuilder: StringBuilder,
        currentMulti: String?,
        currentElements: TreeMap<String, Int>,
        parenthesesElements: TreeMap<String, Int>
    ) {
        if (stringBuilder.isNotEmpty()) {
            //生成元素字符串
            val elementStr = stringBuilder.toString()
            stringBuilder.clear()
            //个数计算
            val multi = calculateMulti(currentMulti)
            //已完成元素增加
            val allowAddElements = TreeMap<String, Int>()
            allowAddElements[elementStr] = multi
            addElement2CurrentMap(currentElements, allowAddElements)
        } else if (parenthesesElements.isNotEmpty()) {
            //倍数计算
            val multi = calculateMulti(currentMulti)
            if (multi > 1) parenthesesElementMulti(parenthesesElements, multi)
            //已完成元素增加
            addElement2CurrentMap(currentElements, parenthesesElements)
            parenthesesElements.clear()
        }
    }


    private fun calculateMulti(currentMulti: String?): Int = currentMulti?.toInt() ?: 1

    //计算添加的元素
    private fun addElement2CurrentMap(
        currentElements: TreeMap<String, Int>,
        allowAddElements: TreeMap<String, Int>
    ) {
        allowAddElements.forEach {
            currentElements[it.key] = (currentElements[it.key] ?: 0) + it.value
        }
    }

    //计算括号内的元素倍数
    private fun parenthesesElementMulti(
        parenthesesElements: TreeMap<String, Int>,
        multi: Int
    ) {
        parenthesesElements.forEach {
            parenthesesElements[it.key] = it.value * multi
        }
    }

}

````

虽然能解决问题但是太慢.