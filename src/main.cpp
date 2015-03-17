    #include <iostream>
    #include <vector>
    #include <cstdio>


    using namespace std;
     
    vector<int> c;
    vector<int> r;
    int length=0;
    char arr[10][10];
    int visited[10][10]={0};
    int n,m;
     
    vector<int> c1;
    vector<int> r1;
     
    void dfs(int i,int j,int count)
    {
     
    if(i>=n || i<0 || j>=m || j<0)
    {
        if(count>length)
            {
                c.clear();
                r.clear();
                length=count;
                int size=c1.size();
                int k=0;
                while(k<size)
                    {
                        c.push_back(c1[k]);
                        r.push_back(r1[k]);
                        k++;
                    }
            
            }
    return;
    }

    if(visited[i][j])
    return;
     
    if(arr[i][j]=='#')
        {
             visited[i][j]=1;
            if(count>length)
                {
                    c.clear();
                    r.clear();
                    length=count;
                    int size=c1.size();
                    int k=0;
                    while(k<size)
                        {
                            c.push_back(c1[k]);
                            r.push_back(r1[k]);
                            k++;
                        }
             
                }
            return;
        }   
     
    visited[i][j]=1;
     
    c1.push_back(j);
    r1.push_back(i);
    dfs(i+1,j,count+1);
     
     
    dfs(i-1,j,count+1);
     
     
    dfs(i,j+1,count+1);
     
     
    dfs(i,j-1,count+1);
     
    c1.pop_back();
    r1.pop_back();
     
     
     
     
    }
     
    int main() {
    freopen("../input_files/in.txt","r",stdin);
    //freopen("../out.txt","w",stdout);
    cin>>n>>m; 
    //int n=7,m=5 ;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
        if(!visited[i][j])
        dfs(i,j,0);
            }
    }
     
    cout<<length<<"\n";
     
     
    for(int i=0;i<c.size();i++)
    {
        arr[r[i]][c[i]]=i+48;
     
    }
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<arr[i][j];
        cout<<"\n";
         
    }
   
    return 0;
    }