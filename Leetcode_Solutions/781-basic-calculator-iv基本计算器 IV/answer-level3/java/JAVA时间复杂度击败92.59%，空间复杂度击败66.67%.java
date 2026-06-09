   RT，通过双栈解决的：一个栈用来存储运算多项式，一个栈用来存储符号。当遇到'('和'*'时，无条件入栈（因为他们的优先级总是最高的）；当遇到'+'或'-'时，判断下栈顶的操作符是否为*或-，如果是这两个则取出操作符、取出栈顶两个多项式进行计算（因为这两个运算符不能按顺序运算：*会改变运算顺序；-会改变多项式的符号），并将计算结果加入到多项式栈中。最终，运算符栈中保存的仅仅是不影响运算顺序的运算符，可以将运算符栈、多项式栈逆序（因为栈是先进后出的，逆序相当于按照元素加入的顺序排序），然后从多项式栈、运算符栈中依次取出元素进行运算即可了。
   代码如下：
   ```
    public List<String> basicCalculatorIV(String expression, String[] evalVars, int[] evalInts) {
        List<String> resultList=new ArrayList<String>();
        if(expression==null||expression.trim().length()==0){
            return resultList;
        }
        Map<String,Integer> evalMap=new HashMap<String, Integer>();
        for(int i=0;i<evalVars.length;i++){
            evalMap.put(evalVars[i],evalInts[i]);
        }
        Stack<Character> operatorStack=new Stack<Character>();
        Stack<Poly> polyStack=new Stack<Poly>();
        for(int i=0;i<expression.length();i++){
            if(expression.charAt(i)==' '){
                continue;
            }
            if(expression.charAt(i)=='('){
                operatorStack.push(expression.charAt(i));
            }
            else if(expression.charAt(i)=='*'){
                operatorStack.push(expression.charAt(i));
            }
            else if(expression.charAt(i)=='+'||expression.charAt(i)=='-'){
                if(!operatorStack.isEmpty()){
                    while(!operatorStack.isEmpty()&&(operatorStack.peek()=='*'||operatorStack.peek()=='-')){
                        char operator=operatorStack.pop();
                        Poly poly2=polyStack.pop();
                        Poly poly1=polyStack.pop();
                        polyStack.push(operate(operator, poly1, poly2));
                    }
                }
                operatorStack.push(expression.charAt(i));
            }
            else if(expression.charAt(i)==')'){
                while (!operatorStack.isEmpty()&&operatorStack.peek()!='(') {
                    char operator=operatorStack.pop();
                    Poly poly2=polyStack.pop();
                    Poly poly1=polyStack.pop();
                    polyStack.push(operate(operator, poly1, poly2));
                }
                operatorStack.pop();
            }
            else if(Character.isDigit(expression.charAt(i))){
                int j=i+1;
                while (j<expression.length()&&Character.isDigit(expression.charAt(j))) {
                    j++;
                }
                int coefficient=Integer.parseInt(expression.substring(i,j));
                i=j-1;
                Variable variable=new Variable();
                List<String> elementList=new ArrayList<String>();
                variable.elementList=elementList;
                variable.coefficient=coefficient;
                List<Variable> variableList=new ArrayList<Variable>();
                variableList.add(variable);
                polyStack.add(new Poly(variableList));
            }
            else if(Character.isAlphabetic(expression.charAt(i))){
                int j=i+1;
                while (j<expression.length()&&Character.isAlphabetic(expression.charAt(j))) {
                    j++;
                }
                int coefficient=1;
                Variable variable=new Variable();
                List<String> elementList=new ArrayList<String>();
                String element=expression.substring(i,j);
                if(evalMap.containsKey(element)){
                    coefficient=evalMap.get(element);
                    element="";
                }
                i=j-1;
                if(!element.equals("")){
                    elementList.add(element);
                }
                variable.elementList=elementList;
                variable.coefficient=coefficient;
                List<Variable> variableList=new ArrayList<Variable>();
                variableList.add(variable);
                polyStack.add(new Poly(variableList));
            }
        }
        while (!operatorStack.isEmpty()&&operatorStack.peek()=='*') {
            Poly poly2=polyStack.pop();
            Poly poly1=polyStack.pop();
            operatorStack.pop();
            polyStack.push(poly1.multiply(poly2));
        }
        List<Poly> polyList=new ArrayList<Poly>();
        List<Character> operatorList=new ArrayList<Character>();
        while (!polyStack.isEmpty()) {
            polyList.add(polyStack.pop());
        }
        Collections.reverse(polyList);
        while (!operatorStack.isEmpty()) {
            operatorList.add(operatorStack.pop());
        }
        Collections.reverse(operatorList);
        Poly resultPoly=polyList.get(0);
        for(int i=1;i<polyList.size();i++){
            Poly tempPoly=polyList.get(i);
            Character operator=operatorList.get(i-1);
            resultPoly=operate(operator,resultPoly,tempPoly);
        }
        resultPoly.format();
        return toList(resultPoly);
    }
    private Poly operate(char operator,Poly poly1,Poly poly2){
        switch (operator) {
            case '+':
                return poly1.add(poly2);
            case '-':
                return poly1.minus(poly2);
            case '*':
                return poly1.multiply(poly2);
        }
        return null;
    }
    private List<String> toList(Poly poly){
        List<String> resultList=new ArrayList<String>();
        List<Variable> variableList=poly.variableList;
        for(Variable var:variableList){
            String tempElementStr=String.join("*",var.elementList);
            String tempResult=var.coefficient+"";
            if(!tempElementStr.equals("")){
                tempResult=tempResult+"*"+tempElementStr;
            }
            resultList.add(tempResult);
        }
        return resultList;
    }
    class Poly{
        List<Variable> variableList;
        public Poly(){
            variableList=new ArrayList<Variable>();
        }
        public Poly(List<Variable> variableList){
            this.variableList=variableList;
        }
        Poly add(Poly poly){
            List<Variable> resultVariableList=new ArrayList<Variable>();
            resultVariableList.addAll(variableList); 
            for(int i=0;i<poly.variableList.size();i++){
                Variable var1=poly.variableList.get(i);
                boolean isFind=false;
                for(int j=0;j<variableList.size();j++){
                    Variable var2=variableList.get(j);
                    if(var1.isVariableCharacterEqualsTo(var2)){
                        resultVariableList.get(j).coefficient=var1.coefficient+resultVariableList.get(j).coefficient;
                        isFind=true;
                    }
                }
                if(!isFind){
                    resultVariableList.add(var1);
                }
            }
            return new Poly(resultVariableList);
        }
        Poly minus(Poly poly){
            List<Variable> resultVariableList=new ArrayList<Variable>();
            resultVariableList.addAll(variableList); 
            for(int i=0;i<poly.variableList.size();i++){
                Variable var1=poly.variableList.get(i);
                boolean isFind=false;
                for(int j=0;j<variableList.size();j++){
                    Variable var2=variableList.get(j);
                    if(var1.isVariableCharacterEqualsTo(var2)){
                        resultVariableList.get(j).coefficient=resultVariableList.get(j).coefficient-var1.coefficient;
                        isFind=true;
                    }
                }
                if(!isFind){
                    var1.coefficient=0-var1.coefficient;
                    resultVariableList.add(var1);
                }
            }
            return new Poly(resultVariableList);
        }
        Poly multiply(Poly poly){
            List<Poly> polyList=new ArrayList<Poly>();
            for(Variable var1:variableList){
                for(Variable var2:poly.variableList){
                    List<Variable> variableList=new ArrayList<Variable>();
                    Variable variable=new Variable();
                    int coefficient=var1.coefficient*var2.coefficient;
                    variable.elementList=new ArrayList<String>();
                    variable.elementList.addAll(var1.elementList);
                    variable.elementList.addAll(var2.elementList);
                    variable.coefficient=coefficient;
                    variable.format();
                    variableList.add(variable);
                    Poly tempPoly=new Poly(variableList);
                    polyList.add(tempPoly);
                }
            }
            Poly resultPoly=polyList.get(0);
            for(int i=1;i<polyList.size();i++){
                resultPoly=resultPoly.add(polyList.get(i));
            }
            return resultPoly;
        }
        void format(){
            List<Variable> removeZeroVariableList=new ArrayList<Variable>();
            for(Variable var:variableList){
                if(var.coefficient!=0){
                    var.format();
                    removeZeroVariableList.add(var);
                }
            }
            Collections.sort(removeZeroVariableList,new Comparator<Variable>() {
            @Override
            public int compare(Variable o1, Variable o2) {
                if(o1.elementList.size()!=o2.elementList.size()){
                    return o2.elementList.size()-o1.elementList.size();
                }
                for(int i=0;i<o1.elementList.size();i++){
                    String element1=o1.elementList.get(i);
                    String element2=o2.elementList.get(i);
                    if(element1.equals(element2)){
                        continue;
                    }
                    String[] elements=new String[2];
                    elements[0]=element1;
                    elements[1]=element2;
                    Arrays.sort(elements);
                    if(element1.equals(elements[0])){
                        return -1;
                    }
                    else{
                        return 1;
                    }
                }
                return 0;
            }});
            this.variableList=removeZeroVariableList;
        }
    }
    class Variable{
        int coefficient;
        List<String> elementList;
        public Variable() {
            coefficient=0;
            elementList=new ArrayList<String>();
        }
        boolean isVariableCharacterEqualsTo(Variable var){
            if(this.elementList.size()==var.elementList.size()){
                for(int i=0;i<elementList.size();i++){
                    if(!this.elementList.get(i).equals(var.elementList.get(i))){
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        void format(){
            if(coefficient==0){
                elementList.clear();
            }
            else{
                if(elementList.size()>0){
                    Collections.sort(elementList);
                }
            }
        }
    }
```
