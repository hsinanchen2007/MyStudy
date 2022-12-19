这个题目关键的是在面试的时候和面试官沟通，考虑特殊的输入参数抛出异常。OOD设计的题目需要在设计完像面试官阐述系统的优劣。当然为了做题，其实不用ood也可以很快给出结果。如果在用ood的时候记得类型转换。 提供一种设计方式，文件和目录都是抽象文件类型。文件和目录都继承自抽象类，文件多一个field是 content 内容，而目录多一个Map 记录其所有子文件或目录。由于一个文件夹内既可以有文件也可以有目录，所以map中的参数类型应该是用抽象类　使得运行时多态。

代码如下。

```java
class FileSystem {

    abstract class AbstractFile {
        String name;
        AbstractFile(String name){
            this.name = name;
        }
        
    }
    
    class Directory extends AbstractFile{
        
        Map<String, AbstractFile> children; //Polymorphism 
        
        public Directory(String name){
            super(name);
            this.children = new HashMap<>();
        }
        
    }
    
    class File extends AbstractFile{
        String content;
        
        public File(String name){
            super(name);
            this.content = "";
        }
        
    }

    private final Directory root;
    
    public FileSystem() {
        root = new Directory("root");
    }
    
    public List<String> ls(String path) {
        String[] strs = getDirectories(path);
            
        Directory curFolder = root;
        AbstractFile child = null; 
      
        for (int i = 1; i < strs.length; i++) {
            child = curFolder.children.get(strs[i]);
            if(child instanceof Directory){
                curFolder = (Directory) child;
            }
        }
      
        // if the last filename represents a file 
        if (child instanceof File){
            child = (File) child;
            return new ArrayList<>(Arrays.asList(child.name));
        }
        
        // Otherwise it is a combination of files and directories.
        List<String> res = new ArrayList<>();
      
        for (String name: curFolder.children.keySet()) res.add(name);
                  
        Collections.sort(res);
      
        return res;
    }
    
    public void mkdir(String path) {
      
        String[] strs = getDirectories(path);
        
        Directory curFolder = root;
        AbstractFile child = null; 
      
        for (int i = 1; i < strs.length; i++) {
                        
            if (!curFolder.children.containsKey(strs[i])) {
                Directory newFolder = new Directory(strs[i]);
                curFolder.children.put(strs[i],newFolder);
            }
            
            child = curFolder.children.get(strs[i]);
            
            if(child instanceof Directory) curFolder = (Directory) child;
        }
    }
    
    
    public void addContentToFile(String filePath, String content) {
        String[] strs = getDirectories(filePath);
        
        Directory curFolder = root;
        AbstractFile child = null; 
      
        for (int i = 1; i < strs.length - 1; i++) {
            child = curFolder.children.get(strs[i]);
            if(child instanceof Directory) curFolder = (Directory) child;
        }
      
        String name = strs[strs.length - 1];
        // create a new file if it does not exist 
        if (!curFolder.children.containsKey(name)) {
            File file = new File(name);
            curFolder.children.put(name, file);
        }
        
        File targetFile = (File) curFolder.children.get(name);
        targetFile.content += content;
    }
    
    public String readContentFromFile(String filePath) {
        
        String[] strs = filePath.split("/");
        
        Directory curFolder = root;
        AbstractFile child = null; 
        
        // operations will be passed valid parameters
        for (int i = 1; i < strs.length - 1; i++) {
            
            child = curFolder.children.get(strs[i]);
            if(child instanceof Directory) curFolder = (Directory) child;
        }
      
        String name = strs[strs.length - 1];
      
        File targetFile = (File) curFolder.children.get(name);
        return targetFile.content; 
    }
  
    
    /*
     * Get the directories by parsing the given path.
     * if the path is just "/", return an Array with just an empty String
     */
    private String[] getDirectories(String path) {
        String[] strs = null;
        if (path.equals("/")) strs = new String[] {""};
        else strs = path.split("/");
        return strs;
    }
}

```
