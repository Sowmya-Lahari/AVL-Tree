#include<iostream>
#include<limits>
#include<climits>
using namespace std;
class student
{
    public:
    int roll;
    int marks;
    student()
    {
        roll=0;
        marks=0;
    }
    student(int x,int y)
    {
        roll=x;
        marks=y;
    }
    void display()
    {
        cout<<"roll:"<<roll<<"\tmarks:"<<marks<<endl;
    }
    void read_student()
    {
        cin>>roll;
        cin>>marks;
    }
};
template <typename T>
class Node{
    public:
    T *data;
    int height;
    int count;
    int cap;
    int lcount;
    int rcount;
    Node<T> *left;
    Node<T> *right;
    Node(T k,int h,int c)
    {
        cap=10;
        data=new T[cap];
        data[0]=k;
        height=h;
        count=c;
        lcount=0;
        rcount=0;
        left=NULL;
        right=NULL;
    }
};

template <typename T>
class comp{
    public:
    int compare(student x,student y)
    {
        if(x.marks==y.marks && x.roll==y.roll)
            return 0;
        else if((x.marks>y.marks && x.roll>y.roll) || (x.marks==y.marks && x.roll>y.roll))
            return 1;
        else if((x.marks<y.marks && x.roll<y.roll) || (x.marks==y.marks && x.roll<y.roll))
            return -1;
        else if (x.roll==y.roll && x.marks<y.marks)
            return -1;
        else if (x.roll==y.roll && x.marks>y.marks)
            return 1;
        else if(x.marks>y.marks)
            return 1;
        else
            return -1;
    }
    student abs_diff(student x,student y)
    {
        student res;
        res.roll=abs(x.roll-y.roll);
        res.marks=abs(x.marks-y.marks);
        return res;
    }
    int compare(int x,int y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(unsigned int x,unsigned int y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(short x,short y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(unsigned short x,unsigned short y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(long x,long y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(unsigned long x,unsigned long y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(long long x,long long y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(unsigned long long x,unsigned long long y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(float x,float y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(char x,char y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(double x,double y)
    {
        if(x>y)
            return 1;
        if(x==y)
            return 0;
        return -1;
    }
    int compare(string x,string y)
    {
        if(x.compare(y)>0)
            return 1;
        if(x.compare(y)==0)
            return 0;
        return -1;
    }
    int abs_diff(int x,int y)
    {
        return abs(x-y);
    }
    long abs_diff(long x,long y)
    {
        return abs(x-y);
    }
    long long abs_diff(long long x,long long y)
    {
        return abs(x-y);
    }
    unsigned int abs_diff(unsigned int x,unsigned int y)
    {
        return x-y;
    }
    unsigned long abs_diff(unsigned long x,unsigned long y)
    {
        return x-y;
    }
    unsigned long long abs_diff(unsigned long long x,unsigned long long y)
    {
        return x-y;
    }
    unsigned short abs_diff(unsigned short x,unsigned short y)
    {
        return x-y;
    }
    short abs_diff(short x,short y)
    {
        return abs((int)x-(int)y);
    }
    char abs_diff(char x,char y)
    {
        return abs((int)x-(int)y);
    }
    float abs_diff(float x,float y)
    {
        return abs(x-y);
    }
    double abs_diff(double x,double y)
    {
        return abs(x-y);
    }
    int abs_diff(string x,string y)
    {
        return 0;
    }

};

template <typename T>
class AVL
{
    Node<T> *root;
    int height;
    public:
    AVL()
    {
        root=NULL;
        height=0;
    }
    void calc_height(Node<T> *cur)
    {
        if(cur->left==NULL && cur->right==NULL)
        {
            cur->height=0;
            return;
        }
        int left=-1,right=-1;
        if(cur->left)
        {
            calc_height(cur->left);
            left=cur->left->height;
        }
        if(cur->right)
        {
            calc_height(cur->right);
            right=cur->right->height;
        }
        cur->height=max(left,right)+1;
        return;
    }
    void rotate_left(Node<T> *cur,Node<T> *parent)
    {
        //cout<<"rotate_left"<<endl;
        Node<T> *temp=cur->right->left;
        cur->right->left=cur;
        if(cur==root)
            this->root=cur->right;
        else if(parent->right==cur)
            parent->right=cur->right;
        else if(parent->left==cur)
            parent->left=cur->right;
        Node<T> *temp2=cur->right;
        cur->right=temp;
        cur->rcount=temp2->lcount;
        temp2->lcount=cur->lcount+cur->rcount+1+temp2->count-1;
        calc_height(temp2);
        return;
    }
    void rotate_right(Node<T> *cur,Node<T> *parent)
    {
        //cout<<"rotate_right"<<endl;
        Node<T> *temp=cur->left->right;
        cur->left->right=cur;
        if(cur==root)
            root=cur->left;
        else if(parent->right==cur)
            parent->right=cur->left;
        else if(parent->left==cur)
            parent->left=cur->left;
        Node<T> *temp2=cur->left;
        cur->left=temp;
        cur->lcount=temp2->rcount+cur->count-1;
        temp2->rcount=cur->lcount+cur->rcount+1;
        calc_height(temp2);
        return;
    }
    void rotate(Node<T> *cur,Node<T> *parent,int left,int right)
    {
        //cout<<left<<"   "<<right<<endl;
        if(left>right)
        {
            int lleft=-1,lright=-1;
            if(cur->left->left)
                lleft=cur->left->left->height;
            if(cur->left->right)
                lright=cur->left->right->height;
            if(lleft>=lright)
                rotate_right(cur,parent);
            else
            {
                //cout<<"here"<<endl;
                rotate_left(cur->left,cur);
                rotate_right(cur,parent);
            }
        }
        else
        {
            int rleft=-1,rright=-1;
            if(cur->right->left)
                rleft=cur->right->left->height;
            if(cur->right->right)
                rright=cur->right->right->height;
            if(rright>=rleft)
                rotate_left(cur,parent);
            else
            {
                rotate_right(cur->right,cur);
                rotate_left(cur,parent);
            }
        }
    }
    void check_balance(Node<T> *cur,Node<T> *par)
    {
        int left=-1,right=-1;
        if(cur->left!=NULL)
            left=cur->left->height;
        if(cur->right!=NULL)
            right=cur->right->height;
        cur->height=max(left,right)+1;
        if(abs(left-right)==2)
            rotate(cur,par,left,right);
        return;
    }
    void rec_ins(Node<T> *cur,Node<T> *parent,T key,comp<T> c)
    {
        if(c.compare(key,cur->data[0])==1)
        {
            if(cur->right==NULL)
            {
                Node<T> *newnode=new Node<T>(key,0,1);
                cur->right=newnode;
                cur->rcount=1;
            }
            else
            {
                rec_ins(cur->right,cur,key,c);
                cur->rcount++;
            }
        }
        else if(c.compare(key,cur->data[0])==0)
        {
            cur->data[cur->count++]=key;
            cur->lcount++;
            return;
        }
        else
        {
            if(cur->left==NULL)
            {
                Node<T> *newnode=new Node<T>(key,0,1);
                cur->left=newnode;
                cur->lcount=1;
            }
            else
            {
                rec_ins(cur->left,cur,key,c);
                cur->lcount++;
            }
        }
        check_balance(cur,parent);
        return;
    }
    void insert(T key,comp<T> c)
    {
        if(root==NULL)
        {
            Node<T> *newnode=new Node<T>(key,0,1);
            root=newnode;
            //this->display(root);
            //cout<<endl;
            root->lcount=0;
            root->rcount=0;
            return;
        }
        rec_ins(root,root,key,c);
        //this->display(root);
        //cout<<endl;
    }
    Node<T>* find_rightmost(Node<T> *cur,Node<T> *par)
    {
        //cout<<cur->data[0]<<endl;
        if(cur->right==NULL)
        {
            par->right=cur->left;
            if(par->right)
                par->height=par->right->height+1;
            
            return cur;
        }
        Node<T> *res=find_rightmost(cur->right,cur);
        if(cur->right)
            cur->rcount=cur->right->lcount+cur->right->rcount+1;
        else
            cur->rcount=0;
        check_balance(cur,par);
        return res;
    }
    void delete_key(T key,comp<T> c)
    {
        delete_node(root,key,c,root);
    }
    void delete_node(Node<T> *cur,T key,comp<T> c,Node<T> *par)
    {
        //cout<<cur->data[0]<<"  "<<key<<endl;
        if(cur==NULL)
            return;
        if(c.compare(key,cur->data[0])==0)
        {
            //cout<<cur->left->data<<" "<<cur->right->data<<endl;
            if(cur->left==NULL && cur->right==NULL)
            {
                //cout<<"case1"<<endl;
                if(cur==root)
                {
                    root=NULL;
                    return;
                }
                int ht=-1;
                if(par->left==cur)
                {
                    par->left=NULL;
                    if(par->right)
                        ht=par->right->height;
                    par->height=ht+1;
                }
                else if(par->right==cur)
                {
                    par->right=NULL;
                    if(par->left)
                        ht=par->left->height;
                    par->height=ht+1;
                }
            }
            else if(cur->left==NULL && cur->right!=NULL)
            {
                //cout<<"case2"<<endl;
                if(cur==root)
                {
                    root=cur->right;
                    return;
                }
                if(par->left==cur)
                    par->left=cur->right;
                else if(par->right==cur)
                    par->right=cur->right;
                cur->right=NULL;
                //return;
            }
            else if(cur->left!=NULL && cur->right==NULL)
            {
                //cout<<"case3"<<endl;
                if(cur==root)
                {
                    root=cur->left;
                    return;
                }
                if(par->left==cur)
                    par->left=cur->left;
                else
                    par->right=cur->left;
                cur->left=NULL;
            }
            else
            {
                //cout<<"case4"<<endl;
                Node<T> *lright;
                //cout<<"cp1"<<endl;
                if(cur->left->right==NULL)
                {
                    lright=cur->left;
                    cur->left=cur->left->left;
                }
                else
                    lright=find_rightmost(cur->left,cur);
                cur->data=lright->data;
                cur->count=lright->count;
                if(cur->left)
                    cur->height=max(cur->left->height,cur->right->height)+1;
                else
                    cur->height=cur->right->height+1;
                cur->lcount--;
            }
        }
        else if(c.compare(key,cur->data[0])==1)
        {
            delete_node(cur->right,key,c,cur);
            if(cur->right)
                cur->rcount=cur->right->lcount+cur->right->rcount+1;
            else
                cur->rcount=0;
        }
        else
        {
            delete_node(cur->left,key,c,cur);
            if(cur->left)
                cur->lcount=cur->left->lcount+cur->left->rcount+1;
            else
                cur->lcount=0;
        }
        check_balance(cur,par);
        return;
    }
    Node<T> * get_root()
    {
        return root;
    }
    T search_util(Node<T> *cur,T key,int flag,T lb,T ub,T cl,int &cnt,int &f,T def,comp<T> c)
    {
        if(cur==NULL)
        {
            //cout<<"here1"<<endl;
            if(flag==0)
                //cout<<"Not present in the tree"<<endl;
                return def;
            else if(flag==1)
                cout<<"0"<<endl;
            else if(flag==2)
            {   
                if(c.compare(lb,def)==0)
                    return def;
                else
                    return lb;
            }
            else if(flag==3)
            {
                if(c.compare(ub,def)==0)
                    return def;
                else
                    return ub;
            }
            else if(flag==4)
                return cl;
            cnt++;
            return def;
        }
        //cout<<c.compare(key,cur->data[0])<<endl;
        if(c.compare(key,cur->data[0])==0)
        {
            //cout<<"here2"<<endl;
            f=cur->count;
            if(flag==0)
                //cout<<"Present in the tree"<<endl;
                return def;
            else if(flag==1)
                cout<<cur->count<<endl;
            else if(flag==2)
                return key;
            else if(flag==3)
            {
                if(cur->right)
                {
                    Node<T> *temp=cur->right;
                    while(temp->left!=NULL)
                        temp=temp->left;
                    if(c.compare(ub,temp->data[0])==1)
                        return temp->data[0];
                    else
                        return ub;
                }
                else if(c.compare(ub,def)==0)
                    return def;
                else
                    return ub;
            }
            else if(flag==4)
                return key;
            cnt+=cur->lcount+1-cur->count+1;
            return def;
        }
        else if(c.compare(key,cur->data[0])==1)
        {
            static T res;
            //cout<<"here3"<<endl;
            if(c.compare(c.abs_diff(key,cur->data[0]),c.abs_diff(key,cl))==-1)
                cl=cur->data[0];
            cnt+=cur->lcount+1;
            //cout<<"\t"<<cnt<<" "<<cur->data[0]<<endl;
            T temp=search_util(cur->right,key,flag,lb,ub,cl,cnt,f,def,c);
            if (c.compare(temp,def)==0)
                return def;
            else
                return temp;
        }
        else
        {
            //cout<<"here4"<<endl;
            if(c.compare(cur->data[0],ub)==-1)
            {
                ub=cur->data[0];
                lb=cur->data[0];
            }
            if(c.compare(c.abs_diff(key,cur->data[0]),c.abs_diff(key,cl))==-1)
                cl=cur->data[0];
            T temp=search_util(cur->left,key,flag,lb,ub,cl,cnt,f,def,c);
            if (c.compare(temp,def)==0)
                return def;
            else
                return temp;
        }
    }
    bool search(T key,comp<T> c,T def)
    {
        int cn=0,f=0;
        search_util(root,key,0,def,def,def,cn,f,def,c);
        if(f==0)
            return false;
        else
            return true;
    }
    void count_occr(T key,comp<T> c,T def)
    {
        int cn=0,f=0;
        search_util(root,key,1,def,def,def,cn,f,def,c);
    }
    T lower_bound(T key,comp<T> c,T def)
    {
        int cn=0,f=0;
        T res=search_util(root,key,2,def,def,def,cn,f,def,c);
        return res;
    }
    T upper_bound(T key,comp<T> c,T def)
    {
        int cn=0,f=0;
        T res=search_util(root,key,3,def,def,def,cn,f,def,c);
        return res;
    }
    T closest(T key,comp<T> c,T def)
    {
        int cn=0,f=0;
        T res=search_util(root,key,4,def,def,def,cn,f,def,c);
        return res;
    }
    T k_largest(Node<T> *cur,int k,T def)
    {
        T res;
        if(cur==this->root)
        {
            k=cur->lcount+cur->rcount+1-k+1;
        }
        //cout<<k<<endl;
        if(k>cur->lcount-cur->count+1 && k<=cur->lcount+1)
            return cur->data[0];
        else if(k<=cur->lcount-cur->count+1)
            res=k_largest(cur->left,k,def);
        else if(k>cur->lcount+1)
            res=k_largest(cur->right,k-cur->lcount-1,def);
        return res;
    }
    void count_in_range(T x,T y,comp<T> c,T def)
    {
        int c1=0,c2=0,f1=0,f2=0;
        T dum1=search_util(root,x,5,def,def,def,c1,f1,def,c);
        dum1=search_util(root,y,5,def,def,def,c2,f2,def,c);
        if(f2>0)
            c2+=f2-1;
        //cout<<c1<<" "<<f1<<" "<<c2<<" "<<f2<<endl;
        if((f1==0 && f2==0) || (f1>0 && f2==0))
            cout<<c2-c1<<endl;
        else
            cout<<c2-c1+1<<endl;
    }
    void display(Node<T> *cur)
    {
        if(cur==NULL)
            return;
        display(cur->left);
        //cur->data[0].display();
        //cout<<" ("<<cur->count<<","<<cur->lcount<<","<<cur->rcount<<") "<<cur->height<<"\t";
        cout<<cur->data[0]<<" ("<<cur->count<<","<<cur->lcount<<","<<cur->rcount<<") "<<cur->height<<"\t";
        display(cur->right);
        return;
    }
};
int main()
{
    typedef unsigned int type;
    AVL<type> *tr=new AVL<type>();
    comp<type> c;
    int ch=1;
    //student def(INT_MAX,INT_MAX);
    int def=INT_MAX;
    while (ch<10)
    {
        cout<<"Enter ch"<<endl;
        cin>>ch;
        //type x;
        type x;
        if(ch==1)
        {
            cin>>x;
            //x.read_student();
            tr->insert(x,c);
        }
        else if(ch==2)
        {
            cin>>x;
            //x.read_student();
            tr->delete_key(x,c);
            //tr->display(tr->get_root());
        }
        else if(ch==3)
        {
            cin>>x;
            //x.read_student();
            if(tr->search(x,c,def))
                cout<<"Present";
            else
                cout<<"Not present";
        }
        else if(ch==4)
        {
            cin>>x;
            //x.read_student();
            tr->count_occr(x,c,def);
        }
        else if(ch==5)
        {
            cin>>x;
            //x.read_student();
            type res=tr->lower_bound(x,c,def);
            cout<<res;
            //res.display();
        }
        else if(ch==6)
        {
            cin>>x;
            //x.read_student();
            type res=tr->upper_bound(x,c,def);
            cout<<res;
            //res.display();
        }
        else if(ch==7)
        {
            cin>>x;
            //x.read_student();
            type res=tr->closest(x,c,def);
            cout<<res;
            //res.display();
        }
        else if(ch==8)
        {
            int k;
            cin>>k;
            type res=tr->k_largest(tr->get_root(),k,def);
            cout<<res;
            //res.display();
        }
        else if(ch==9)
        {
            cin>>x;
            //x.read_student();
            type y;
            cin>>y;
            //y.read_student();
            tr->count_in_range(x,y,c,def);
        }
        tr->display(tr->get_root());
    }
    return 0;
}