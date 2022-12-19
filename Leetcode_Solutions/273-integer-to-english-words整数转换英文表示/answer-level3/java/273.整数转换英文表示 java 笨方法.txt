    public static String intToRoman(int num) {
        String strnum = Integer.toString(num);
        int len = strnum.length();
        int temp = 0;
        int index = len;
        boolean flag = false;
        String s = "";
        for (int i = 0; i < len; i++){
            switch (strnum.charAt(i)){
                case '1':
                    if ((i + 1 < len && i + 2 >= len) || (len == 8 && i != 1 && i != 2 && i != 4) || (len == 5 && i != 1 && i != 2) || flag){
                        switch (strnum.charAt(i + 1)){
                            case '1':
                                s += "Eleven ";
                                i++;
                                index--;
                                break;
                            case '2':
                                s += "Twelve ";
                                i++;
                                index--;
                                break;
                            case '3':
                                s += "Thirteen ";
                                i++;
                                index--;
                                break;
                            case '4':
                                s += "Fourteen ";
                                i++;
                                index--;
                                break;
                            case '5':
                                s += "Fifteen ";
                                i++;
                                index--;
                                break;
                            case '6':
                                s += "Sixteen ";
                                i++;
                                index--;
                                break;
                            case '7':
                                s += "Seventeen ";
                                i++;
                                index--;
                                break;
                            case '8':
                                s += "Eighteen ";
                                i++;
                                index--;
                                break;
                            case '9':
                                s += "Nineteen ";
                                i++;
                                index--;
                                break;
                            case '0':
                                s += "Ten ";
                                i++;
                                index--;
                                break;
                        }
                        break;
                    }else{
                        s += "One ";
                        break;
                    }
                case '2':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Twenty ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Twenty ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Twenty ";
                                break;
                            }
                        }
                    }
                    s += "Two ";
                    break;
                case '3':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Thirty ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Thirty ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Thirty ";
                                break;
                            }
                        }
                    }
                    s += "Three ";
                    break;
                case '4':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Forty ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Forty ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Forty ";
                                break;
                            }
                        }
                    }
                    s += "Four ";
                    break;
                case '5':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Fifty ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Fifty ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Fifty ";
                                break;
                            }
                        }
                    }
                    s += "Five ";
                    break;
                case '6':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Sixty ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Sixty ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Sixty ";
                                break;
                            }
                        }
                    }
                    s += "Six ";
                    break;
                case '7':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Seventy ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Seventy ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Seventy ";
                                break;
                            }
                        }
                    }
                    s += "Seven ";
                    break;
                case '8':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Eighty ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Eighty ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Eighty ";
                                break;
                            }
                        }
                    }
                    s += "Eight ";
                    break;
                case '9':
                    if (i + 1 < len){
                        if (flag == true){
                            s += "Ninety ";
                            break;
                        }else if (i + 2 >= len){
                            s += "Ninety ";
                            break;
                        }else if (len == 8 || len == 5){
                            if (i == 0){
                                s += "Ninety ";
                                break;
                            }
                        }
                    }
                    s += "Nine ";
                    break;
                case '0':
                    if (len == 1){
                        s += "Zero ";
                        break;
                    }
                    s += "";
                    break;
            }
            flag = false;
            if (index >= 10){
                if (strnum.charAt(i) == '0'){
                    s += "";
                }else {
                    s += "Billion ";
                }
            }else if (index >= 7){
                temp = index - 7 + 1;
                if (temp == 3){
                    if (strnum.charAt(i) == '0'){
                        s += "";
                        if (i + 1 < len){
                            flag = true;
                        }
                    }else {
                        s += "Hundred ";
                        if (i + 1 < len){
                            flag = true;
                        }
                    }
                }else if (temp == 2){
                    s += "";
                }else {
                    /*if (strnum.charAt(i) == '0'){
                        s += "";
                    }else {
                        s += "Million ";
                    }*/
                    String[] sub = s.split(" ");
                    if ("Billion".equals(sub[sub.length-1])){
                        s += "";
                    }else {
                        s += "Million ";
                    }
                }
            }else if (index >= 4){
                temp = index - 4 + 1;
                if (temp == 3){
                    if (strnum.charAt(i) == '0'){
                        s += "";
                        if (i + 1 < len){
                            flag = true;
                        }
                    }else {
                        s += "Hundred ";
                        if (i + 1 < len){
                            flag = true;
                        }
                    }
                }else if (temp == 2){
                    s += "";
                }else {
                    String[] sub = s.split(" ");
                    if (strnum.charAt(i) == '0' && ("Billion".equals(sub[sub.length-1]) || "Million".equals(sub[sub.length-1]))){
                        s += "";
                    }else {
                        s += "Thousand ";
                    }
                }
            }else{
                temp = index;
                if (temp == 3){
                    if (strnum.charAt(i) == '0'){
                        s += "";
                        if (i + 1 < len){
                            flag = true;
                        }
                    }else{
                        s += "Hundred ";
                        if (i + 1 < len){
                            flag = true;
                        }
                    }
                }else if (temp == 2){
                    s += "";
                }else {
                    s += "";
                }
            }
            index--;
        }
        String a = s.substring(0, s.length()-1);
        return a;
    }

逻辑比较low，这种方法内存占用比较少，超过80%左右，运行超过60%。是一点一点调试出来的，花了接近8个小时，大家随便看一下就行，还是得继续学习大佬的精简解法。
