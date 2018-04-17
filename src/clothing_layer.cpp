#include "clothing_layer.h"

#include "json.h"

#include <map>

std::map<std::string, clothing_layer> clothing_layers_all;


const clothing_layer & clothing_layer::get( const std::string & id )
{
	static clothing_layer null_layer;
	auto iter = clothing_layers_all.find( id );
	return iter != clothing_layers_all.end() ? iter->second : null_layer;
}

void clothing_layer::load( JsonObject & jo )
{
	auto id = jo.get_string( "id" );
	auto &l = clothing_layers_all.emplace( id, clothing_layer( id ) ).first->second;

	l.level = jo.get_enum_value<layer_level>( "layer" );
    l.color = color_from_string( jo.get_string( "color" ) );
	l.symbol = jo.get_string( "symbol" )[0];
}

void clothing_layer::reset()
{
	clothing_layers_all.clear();
}
