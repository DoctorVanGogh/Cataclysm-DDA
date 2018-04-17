#pragma once
#ifndef CLOTHING_LAYER_H
#define CLOTHING_LAYER_H

#include "color.h"
#include "item.h"

#include <string>

class JsonObject;

using itype_id = std::string;

class clothing_layer
{
        friend class DynamicDataLoader;
    public:
		/** Fetches flag definition (or null flag if not found) */
		static const clothing_layer &get( const std::string &id );

    private:
        const std::string id;
        char symbol;
        nc_color color;
        layer_level level;


        clothing_layer( const std::string &id = std::string() ) : id( id ) {}

        static void load( JsonObject &jo );

        static void reset();

};

#endif
