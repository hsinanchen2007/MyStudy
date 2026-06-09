思路：
1. 直接比较两者是否相等；
2. 如果不想等，判断是否长度相等且不含*，如果含？，遍历每个字符比较，字符相等，或者是？，反之则为不匹配；不含？，不匹配；
3. 如果含有*，则以*为界限，分为多个字符串，然后每个子字符串去跟对应剩余未匹配过的字符串匹配，如果都匹配，则整个匹配，如果一个不匹配，则都不匹配；
4. 如果不包含*，则肯定不匹配。
时间复杂度：最大O(n*m)
```
func isMatch(_ s: String, _ p: String) -> Bool {
        if s == p { ///直接比较，相等，返回
            return true
        }else{///不想等，则可能含有其他特殊符号？、 *等
            if s.count == p.count && !p.contains("*"){///长度相等，且不含有*，则含有？
                if p.contains("?") {
                    for i in 0..<p.count {///遍历比较
                        let index = s.index(s.startIndex, offsetBy: i)
                        if s[index] != p[index] && p[index] != "?" {///比较原则，如果每个字符不想等，且不是？，则不匹配
                            
                            return false
                        }
                    }
                    return true
                }else{///不含？，肯定不匹配
                    return false
                }
            }else{///长度不想等或者含有*，如果不含*，这种情况肯定不匹配
                if p.contains("*") {///含有*
                    let strings = p.components(separatedBy: "*")///将字符串以*隔开的子字符串组成的数组
                    var tempStrings = strings
                    tempStrings.removeAll(where: {$0 == ""})
                    if tempStrings.count == 0{//////如果只含有空字符串，则说明只有*，肯定匹配
                        return true
                    }
                    var startCompare = 0///开始比较的位置，接着上一次比较
                    var k = 0
                    var isStartFirst = false///是否以*开头
                    
                    for compoment in strings{///遍历子字符串组成的数组比较
                        if startCompare + compoment.count > s.count {///开始比较的位置+剩余比较的长度>s.count，肯定不匹配
                            return false
                        }
                        if compoment.count == 0{///空字符，说明以*开头，或者结尾
                            if k == 0{///以*开头，标记
                                isStartFirst = true
                            }
                            if k == strings.count - 1 {///以*结尾，走到这里，说明前面的已经匹配，*肯定匹配
                                return true
                            }
                            k += 1
                            continue
                        }
                        
                        if k > 0 && k == strings.count - 1 { ///如果子字符串的数量不等于一，则最后一个子字符串需要跟最后对应的子字符串匹配
                            startCompare = s.count - compoment.count
                        }
                        var temps = s
                        if startCompare != 0{///剔除掉已经比较了的字符串
                            let startI = s.index(s.startIndex, offsetBy: startCompare - 1)
                            temps.removeSubrange(s.startIndex...startI)
                        }
                        
                        if !(temps.contains(compoment)){///剩余未匹配的字符串，不包含子字符串
                            if compoment.contains("?") {///如果包含？
                                for i in startCompare..<s.count{///遍历比较，比较原则，字符不想等，且不为？，则不匹配，更新开始比较的位置，继续比较
                                    var isMatch = true
                                    for j in 0..<compoment.count{
                                        if i + j > s.count - 1{
                                            return false
                                        }
                                        let sindex = s.index(s.startIndex, offsetBy: i+j)
                                        let cindex = compoment.index(compoment.startIndex, offsetBy: j)
                                        if compoment[cindex] != s[sindex] && compoment[cindex] != "?"{
                                            if i >= s.count - compoment.count || (!isStartFirst && startCompare == 0) {///如果是第一组，且不是以*开头，则肯定不匹配；如果是最后一组，也肯定不匹配
                                                return false
                                            }
                                            
                                            isMatch = false///不匹配，跳出循环
                                            break
                                        }
                                    }
                                    if isMatch {///匹配到，更新开始匹配位置，跳出循环
                                        startCompare = i + compoment.count
                                        break
                                    }
                                }
                                
                            }else{///如果不包含？，肯定不匹配
                                return false
                            }
                        }else{///剩余未匹配的字符串，包含子字符串，查询位置

                            let range = temps.range(of: compoment)
                            if startCompare == 0 && !isStartFirst{///第一组，且不以*开头
                                let lower = temps.distance(from: s.startIndex, to: range!.lowerBound)
                                if lower != 0{///匹配到的位置不是0，则肯定不匹配
                                    return false
                                }
                            }
                            let up = range!.upperBound
                            startCompare += temps.distance(from: s.startIndex, to: up)///更新开始匹配的位置
                           
                        }
                        k += 1
                    }
                    return true
                
                }else{///不含*，肯定不匹配
                    return false
                }
            }
        }
       
    }
```
