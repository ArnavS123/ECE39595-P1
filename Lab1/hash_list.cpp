#include "hash_list.h"

hash_list::hash_list() {}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value)
{
    node* curr = head;

    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    node* new_node = new node{key, value, nullptr}; // next is set to nullptr (end of list)
    head = new_node;

    size++;
    return;
}

std::optional<float> hash_list::get_value(int key) const
{
    node* curr = head;

    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            return(curr->value);
        }
        curr = curr->next;
    }

    return(std::nullopt);
}

bool hash_list::remove(int key)
{
    node* curr = head;
    node* prev = nullptr;

    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            if (curr == head)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete(curr);
            size--;
            return(true);
        }
        prev = curr;
        curr = curr->next;
    }

    return(false);
}

size_t hash_list::get_size() const
{
    return(size);
}

hash_list::~hash_list()
{
    node* curr = head;

    while (curr != nullptr)
    {
        node* next_curr = curr->next;
        delete(curr);
        curr = next_curr;
    }

    return;
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
