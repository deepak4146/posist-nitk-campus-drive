
#include <iostream>
#include<string.h>
using namespace std;
struct data
{
    int owner_id;
    float value;
    string owner_name;
    
};
struct timestamp
{
    int date;
    int month;
    int year;
};
struct record{
    struct timestamp *t;
    struct data *d;
    int nodeNumber;
    string nodeId;
    string referenceNodeId;
    string childReferNodeId;
    string genesisreferncenodeid;
    string HashValue;
    struct record *left;
    struct record * right
} ;

struct record * create_node(    struct record *record,struct data * data,struct timestamp *t,int nodeNumber,string nodeId,string referenceNodeId,string childReferNodeId, string genesisreferncenodeid,string HashValue)
{
    
    record->d=data;
    record->t=t;
    record->nodeNumber=nodeNumber;
    record->nodeId=nodeId;
    record->referenceNodeId=referenceNodeId;
    record->childReferNodeId=childReferNodeId;
     record->genesisreferncenodeid=genesisreferncenodeid;
    record->HashValue=HashValue;
    record->left=NULL;
    record->right=NULL;
    return record;
    
    
}
struct record *create_genesis(struct record * gene,struct data * data,struct timestamp *t,int nodeNumber,string nodeId,string childReferNodeId,string HashValue)
{
    
     gene=create_node(gene,data,t,nodeNumber,nodeId,NULL,childReferNodeId,&gene,HashValue);
    return gene;
}
struct record* create_set_child(struct record *parent,struct record * child1,struct record* child2)
{
    if(parent->data->value>=(child1->data->value + child2->data->value))
    {
        child1->referenceNodeId=parent;
        child2->referenceNodeId=parent;
        parent->genesisreferncenodeid=child1;
    }
}

struct record *edit_value(struct record *gene,float value_to_be_replaced,float value_to_be_added)
{
    struct record *r=gene;
    struct record *s=gene
    // assuming child1 to be smaller than child2
    
    else if(gene->data->value==value_to_be_replaced)
    {
        gene->data->value=value_to_be_added;
    }
    else 
    {
        if(gene->left==NULL)
        { 
            printf("not found\n");
            return
        }
        else{
    
        r=gene->left;
        edit_value(r,value_to_be_replaced,value_to_be_added);
        }
        if(gene->right==NULL)
        { 
            printf("not found\n");
            return
        }
        else{
    
        s=gene->right;
        edit_value(s,value_to_be_replaced,value_to_be_added);
        }
    }
}
